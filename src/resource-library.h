#ifndef RESOURCELIBRARY_H
#define RESOURCELIBRARY_H

class ResourceLibrary
{
public:
   virtual ~ResourceLibrary() {}
   virtual bool initialize() = 0;
};

#endif