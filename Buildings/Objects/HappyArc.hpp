#ifndef _HAPPYARC_
#define _HAPPYARC_

#include "Object.hpp"
// #include "../BoundingVolumes/BSphere.hpp"

/** @brief an arc */
class HappyArc : public Object
{
  public :
    /**
  \param r radius.
  \param q quality
  \param eps epaisseur.
  \param l longeur.
    */
    HappyArc(float r, float l, float eps,int q = 20);
    /** @brief rebuild the arc with other parameters */
    void rebuild(float r, float l, float eps,int q);
  protected :
    void build() const;
    float radius, epaisseur,largeur;
    int quality;
};

#endif
