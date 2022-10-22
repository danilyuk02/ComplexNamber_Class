//Автор Danilova Galina
#pragma once

#include <string>
#include "ComplexNumber.h"

void to_file(const std::string& name_file, const ComplexNumber& n);
ComplexNumber from_file(const std::string& name_file, ComplexNumber& n);