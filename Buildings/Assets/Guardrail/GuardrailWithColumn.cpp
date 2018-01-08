#include <Architect.hpp>
#include "GuardrailWithColumn.hpp"

GuardrailWithColumn::GuardrailWithColumn()
{
  style = CLASSIC;
}

void GuardrailWithColumn::setBuiltIn()
{
  bv = new AABB(height, width, depth);

  int j=0;
  for (float i=0; i<width; i+=space)
  {
    Column* c = dynamic_cast<Column*>(archi->get("G_COLUMN"));
    c->set(depth*4/5, height-0.1);
    c->translateOf(i, depth*0.1, 0);
    addAsset(c);
    j++;
  }
  Box* b = new Box(0.1, width, depth);
  b->translateOf(0, 0, height-0.1);
  addObject(b);
}
