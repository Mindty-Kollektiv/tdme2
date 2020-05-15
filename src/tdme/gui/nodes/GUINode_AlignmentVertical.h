#pragma once

#include <string>

#include <tdme/gui/nodes/fwd-tdme.h>
#include <tdme/utils/Enum.h>

using std::string;

using tdme::utils::Enum;
using tdme::gui::nodes::GUINode_AlignmentHorizontal;
using tdme::gui::nodes::GUINode_Alignments;
using tdme::gui::nodes::GUINode_Border;
using tdme::gui::nodes::GUINode_ComputedConstraints;
using tdme::gui::nodes::GUINode_Flow;
using tdme::gui::nodes::GUINode_Padding;
using tdme::gui::nodes::GUINode_RequestedConstraints_RequestedConstraintsType;
using tdme::gui::nodes::GUINode_RequestedConstraints;
using tdme::gui::nodes::GUINode;
using tdme::gui::nodes::GUINode_AlignmentVertical;

/**
 * GUI node vertical alignment enum
 */
class tdme::gui::nodes::GUINode_AlignmentVertical final: public Enum
{
public:
	static GUINode_AlignmentVertical* NONE;
	static GUINode_AlignmentVertical* TOP;
	static GUINode_AlignmentVertical* CENTER;
	static GUINode_AlignmentVertical* BOTTOM;
	GUINode_AlignmentVertical(const string& name, int ordinal);
	static GUINode_AlignmentVertical* valueOf(const string& a0);
};
