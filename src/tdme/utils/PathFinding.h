#pragma once

#include <map>
#include <stack>
#include <string>
#include <vector>

#include <tdme/tdme.h>
#include <tdme/engine/Transformations.h>
#include <tdme/engine/physics/World.h>
#include <tdme/engine/primitives/BoundingVolume.h>
#include <tdme/math/Math.h>
#include <tdme/math/Vector3.h>
#include <tdme/utils/Console.h>
#include <tdme/utils/PathFindingNode.h>
#include <tdme/utils/PathFindingCustomTest.h>

using std::map;
using std::stack;
using std::string;
using std::to_string;
using std::vector;

using tdme::engine::Transformations;
using tdme::engine::physics::World;
using tdme::engine::primitives::BoundingVolume;
using tdme::math::Math;
using tdme::math::Vector3;
using tdme::utils::Console;
using tdme::utils::PathFindingNode;
using tdme::utils::PathFindingCustomTest;

/**
 * Path finding class
 * @author Andreas Drewke
 * @version $Id$
 */
class tdme::utils::PathFinding final
{
public:
	enum PathFindingStatus {PATH_STEP, PATH_FOUND, PATH_NOWAY};

	static constexpr bool VERBOSE { false };

	struct DijkstraCellStruct {
		string id;
		bool tested;
		Vector3 position;
		bool walkable;
		float costs;
	};

	/**
	 * Flow map cell
	 * @author Andreas Drewke
	 * @version $Id$
	 */
	class FlowMapCell {
		friend class PathFinding;
		private:
			/**
			 * Private constructor
			 * @param position position
			 * @param walkable walkable
			 * @param direction direction
			 */
			FlowMapCell(const Vector3& position, bool walkable, const Vector3& direction): position(position), walkable(walkable), direction(direction) {
			}

		public:
			/**
			 * @return cell position
			 */
			inline const Vector3& getPosition() const {
				return position;
			}

			/**
			 * @return if cell is walkable
			 */
			inline bool isWalkable() const {
				return walkable;
			}

			/**
			 * @return cell movement direction
			 */
			inline const Vector3& getDirection() const {
				return direction;
			}

		private:
			Vector3 position;
			bool walkable;
			Vector3 direction;
	};

	/**
	 * Flow map cell
	 * @author Andreas Drewke
	 * @version $Id$
	 */
	class FlowMap {
		friend class PathFinding;
		private:
			float stepSize;
			map<string, const FlowMapCell*> cells;

			/**
			 * Adds a cell to flow map
			 * @param cell cell
			 */
			void addCell(const FlowMapCell* cell) {
				auto cellId = toKey(
					Math::floor(cell->getPosition().getX() / stepSize) * stepSize,
					Math::floor(cell->getPosition().getZ() / stepSize) * stepSize
				);
				cells[cellId] = cell;
			}

		public:
			/**
			 * Constructor
			 */
			FlowMap(float stepSize): stepSize(stepSize) {
			}

			/**
			 * Get cell
			 * @param x x
			 * @param z z
			 */
			const FlowMapCell* getCell(float x, float z) {
				auto cellId = toKey(
					Math::floor(x / stepSize) * stepSize,
					Math::floor(z / stepSize) * stepSize
				);
				auto cellIt = cells.find(cellId);
				if (cellIt == cells.end()) return nullptr;
				return cellIt->second;
			}

			/**
			 * Dump to console
			 */
			void dump() {
				for (auto it: cells) {
					auto id = it.first;
					auto& cell = *it.second;
					auto cellId = toKey(
						Math::floor(cell.position.getX() / stepSize) * stepSize,
						Math::floor(cell.position.getZ() / stepSize) * stepSize
					);
					Console::println(
						"id: " + cellId + ", " +
						"position:" +
						to_string(cell.getPosition().getX()) + ", " +
						to_string(cell.getPosition().getY()) + ", " +
						to_string(cell.getPosition().getZ()) + "; " +
						"walkable: " +
						to_string(cell.walkable) + "; " +
						"direction: " +
						to_string(cell.getDirection().getX()) + "; " +
						to_string(cell.getDirection().getY()) + ", " +
						to_string(cell.getDirection().getZ())
					);
				}
			}

	};

	/**
	 * Public constructor
	 * @param world world
	 * @param sloping sloping
	 * @param stepsMax steps max
	 * @param actorHeight actor height
	 * @param stepSize step size
	 * @param stepSizeLast step size last
	 * @param actorStepUpMax actor step up max
	 * @param skipOnCollisionTypeIds skip cells with given collision type ids
	 * @param maxTries max tries
	 */
	PathFinding(World* world, bool sloping = false, int stepsMax = 1000, float actorHeight = 2.0f, float stepSize = 0.5f, float stepSizeLast = 0.75f, float actorStepUpMax = 0.25f, uint16_t skipOnCollisionTypeIds = 0, int maxTries = 5);

	/**
	 * Destructor
	 */
	~PathFinding();

	/**
	 * Return string representation of given x,y,z for path finding key
	 * @param x x
	 * @param y y
	 * @param z z
	 * @return string representation
	 */
	inline static string toKey(float x, float y, float z) {
		string result;
		int32_t value = 0;
		result.reserve(sizeof(value) * 3);
		value = static_cast<int>(x * 10.0f);
		result.append((char*)&value, sizeof(value));
		value = static_cast<int>(y * 10.0f);
		result.append((char*)&value, sizeof(value));
		value = static_cast<int>(z * 10.0f);
		result.append((char*)&value, sizeof(value));
		return result;
	}

	/**
	 * Return string representation of given x,z for path finding key
	 * @param x x
	 * @param y y
	 * @param z z
	 * @return string representation
	 */
	inline static string toKey(float x, float z) {
		string result;
		int32_t value = 0;
		value = static_cast<int>(x * 10.0f);
		result.append(to_string(value));
		result.append(",");
		value = static_cast<int>(z * 10.0f);
		result.append(to_string(value));
		return result;
	}

	/**
	 * Finds path to given end position
	 * @param startPosition start position
	 * @param endPosition end position
	 * @param collisionTypeIds collision type ids
	 * @param path path from actor to target
	 * @param alternativeEndSteps alternative end steps
	 * @param customTest custom test
	 * @return success
	 */
	bool findPath(const Vector3& startPosition, const Vector3& endPosition, const uint16_t collisionTypeIds, vector<Vector3>& path, int alternativeEndSteps = 0, PathFindingCustomTest* customTest = nullptr);

	/**
	 * Checks if a cell is walkable
	 * @param x x
	 * @param y y
	 * @param z z
	 * @param height y stepped up
	 * @param collisionTypeIds collision type ids or 0 for default
	 * @param ignoreStepUpMax ignore step up max
	 * @return if cell is walkable
	 */
	bool isWalkable(float x, float y, float z, float& height, uint16_t collisionTypeIds = 0, bool ignoreStepUpMax = false);

	/**
	 * Create flow map
	 * @param endPosition end position
	 * @param center flow map center
	 * @param depth flow map depth
	 * @param width flow map width
	 * @param collisionTypeIds collision type ids
	 * @param customTest custom test
	 */
	FlowMap* createFlowMap(map<string, DijkstraCellStruct>& dijkstraCellMap, const Vector3& endPosition, const Vector3& center, float depth, float width, const uint16_t collisionTypeIds, PathFindingCustomTest* customTest = nullptr);

private:
	/**
	 * Reset path finding
	 */
	void reset();

	/**
	 * Computes non square rooted distance between a and b
	 * @param a a
	 * @param b b
	 * @return non square rooted distance
	 */
	inline float computeDistance(PathFindingNode* a, PathFindingNode* b) {
		float dx = a->x - b->x;
		float dy = a->y - b->y;
		float dz = a->z - b->z;
		return (dx * dx) + (dy * dy) + (dz * dz);
	}

	/**
	 * Returns if nodes are equals
	 * @param a a
	 * @param bX b x coordinate
	 * @param bY b y coordinate
	 * @param bZ b z coordinate
	 * @return if node a == node b
	 */
	inline bool equals(PathFindingNode* a, float bX, float bY, float bZ) {
		return
			(
				Math::abs(a->x - bX) < 0.1f &&
				Math::abs(a->y - bY) < 0.1f &&
				Math::abs(a->z - bZ) < 0.1f
			);
	}

	/**
	 * Returns if nodes are equals for (last node test)
	 * @param a a
	 * @param lastNode b
	 * @return if node a == node b
	 */
	inline bool equalsLastNode(PathFindingNode* a, PathFindingNode* lastNode) {
		return
			(a == lastNode) ||
			(
				Math::abs(a->x - lastNode->x) < stepSizeLast &&
				Math::abs(a->y - lastNode->y) < stepSizeLast &&
				Math::abs(a->z - lastNode->z) < stepSizeLast
			);
	}

	/**
	 * Checks if a cell is walkable
	 * @param x x
	 * @param y y
	 * @param z z
	 * @param height y stepped up
	 * @param collisionTypeIds collision type ids or 0 for default
	 * @param ignoreStepUpMax ignore step up max
	 * @return if cell is walkable
	 */
	bool isWalkableInternal(float x, float y, float z, float& height, uint16_t collisionTypeIds = 0, bool ignoreStepUpMax = false);

	/**
	 * Sets up the PathFinding, it needs to be called after constructing the object
	 * @param startPosition start position
	 * @param endPosition end position
	 */
	void start(const Vector3& startPosition, const Vector3& endPosition);

	/**
	 * Processes one step in AStar path finding
	 * @return step status
	 */
	PathFindingStatus step();

	// properties
	World* world;
	PathFindingCustomTest* customTest;
	bool sloping;
	int stepsMax;
	float actorHeight;
	float stepSize;
	float stepSizeLast;
	float actorStepUpMax;
	uint16_t skipOnCollisionTypeIds;
	uint16_t collisionTypeIds;
	int maxTries;
	PathFindingNode end;
	stack<PathFindingNode*> successorNodes;
	map<string, PathFindingNode*> openNodes;
	map<string, PathFindingNode*> closedNodes;
	BoundingVolume* actorBoundingVolume;
	BoundingVolume* actorBoundingVolumeSlopeTest;
};
