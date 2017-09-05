// Generated from /tdme/src/tdme/tools/shared/model/PropertyModelClass.java
#include <tdme/tools/shared/model/PropertyModelClass.h>

#include <java/lang/String.h>
#include <java/lang/StringBuilder.h>

using tdme::tools::shared::model::PropertyModelClass;
using java::lang::String;
using java::lang::StringBuilder;

PropertyModelClass::PropertyModelClass(const wstring& name, const wstring& value)
{
	this->name = name;
	this->value = value;
}

const wstring& PropertyModelClass::getName()
{
	return name;
}

void PropertyModelClass::setName(const wstring& name)
{
	this->name = name;
}

const wstring& PropertyModelClass::getValue()
{
	return value;
}

void PropertyModelClass::setValue(const wstring& value)
{
	this->value = value;
}

PropertyModelClass* PropertyModelClass::clone()
{
	return new PropertyModelClass(name, value);
}
