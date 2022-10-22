//Автор Danilova Galina
#include "ModulCN.h"
#include "ComplexNumber.h"
#include <fstream> // Запись и чтение файла
#include <cstdlib>

void to_file(const std::string& name_file, const ComplexNumber& n) {
    using namespace std;
    ofstream out(name_file);
    out << n.get_r() << " " << n.get_i();
    out.close();
}

ComplexNumber from_file(const std::string& name_file, ComplexNumber& n) {
    using namespace std;
    ifstream in(name_file);
    string name;
    in >> name;
    n.set_r(atof(name.c_str()));
    in >> name;
    n.set_i(atof(name.c_str()));
    in.close();
    return n;
}