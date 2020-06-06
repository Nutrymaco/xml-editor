#ifndef PERSONFILEREPOSITORY_H
#define PERSONFILEREPOSITORY_H

#include "persondto.h"
#include "personxmlconverter.h"
#include <abstractfilerepository.h>

class PersonFileRepository : public AbstractFileRepository<PersonDTO, PersonXMLConverter>
{
public:
};

#endif // PERSONFILEREPOSITORY_H
