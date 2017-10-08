#pragma once

#include <tdme.h>
#include <tdme/gui/nodes/fwd-tdme.h>

using tdme::gui::nodes::GUIColor;
using tdme::gui::nodes::GUINode_AlignmentHorizontal;
using tdme::gui::nodes::GUINode_AlignmentVertical;
using tdme::gui::nodes::GUINode_Alignments;
using tdme::gui::nodes::GUINode_ComputedConstraints;
using tdme::gui::nodes::GUINode_Flow;
using tdme::gui::nodes::GUINode_Padding;
using tdme::gui::nodes::GUINode_RequestedConstraints_RequestedConstraintsType;
using tdme::gui::nodes::GUINode_RequestedConstraints;
using tdme::gui::nodes::GUINode;

/** 
 * Border
 * @author Andreas Drewke
 * @version $Id$
 */
class tdme::gui::nodes::GUINode_Border
{

public:
	GUIColor* leftColor {  };
	GUIColor* topColor {  };
	GUIColor* rightColor {  };
	GUIColor* bottomColor {  };
	int32_t left {  };
	int32_t top {  };
	int32_t right {  };
	int32_t bottom {  };

	GUINode_Border();

private:
	friend class GUINode;
	friend class GUINode_Flow;
	friend class GUINode_AlignmentHorizontal;
	friend class GUINode_AlignmentVertical;
	friend class GUINode_Alignments;
	friend class GUINode_RequestedConstraints;
	friend class GUINode_RequestedConstraints_RequestedConstraintsType;
	friend class GUINode_ComputedConstraints;
	friend class GUINode_Padding;
};
