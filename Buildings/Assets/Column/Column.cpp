#include "Column.hpp"

Column::Column()
{
  type = "G_COLUMN";
}

Column::~Column()
{
  ;
}

void Column::set(float w, float h)
{
  width = w;
  height = h;
  setBuiltIn();
  build();
}
