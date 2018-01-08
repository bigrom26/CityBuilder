#include "Factory.hpp"
#include <stdlib.h>

Factory::Factory()
{
}

Factory::~Factory()
{
  ;
}


Asset* Factory::getAsset(string type)
{
  if(type == "")
    return NULL;

  //--Buildings--
  else if(type=="BasicBuilding")
    return dynamic_cast<Asset*>(dynamic_cast<Building*>(new BasicBuilding()));
  else if(type=="SkyscraperBuilding")
    return dynamic_cast<Asset*>(dynamic_cast<Building*>(new SkyscraperBuilding()));

  //--Floors--
  else if(type=="BasicBottomFloor")
    return dynamic_cast<Asset*>(dynamic_cast<BottomFloor*>(new BasicBottomFloor()));
  else if(type=="CommercialBottomFloor")
    return dynamic_cast<Asset*>(dynamic_cast<BottomFloor*>(new BasicBottomFloor()));
  else if(type=="BottomFloorWithTwoFacades")
    return dynamic_cast<Asset*>(dynamic_cast<BottomFloor*>(new BottomFloorWithTwoFacades()));
  else if(type=="BasicTopFloor")
    return dynamic_cast<Asset*>(dynamic_cast<TopFloor*>(new BasicTopFloor()));
  else if(type=="WorkingTopFloor")
    return dynamic_cast<Asset*>(dynamic_cast<TopFloor*>(new WorkingTopFloor()));
  else if(type=="TopFloorWithTwoFacades")
    return dynamic_cast<Asset*>(dynamic_cast<TopFloor*>(new TopFloorWithTwoFacades()));
  else if(type=="BasicMiddleFloor")
    return dynamic_cast<Asset*>(dynamic_cast<MiddleFloor*>(new BasicMiddleFloor()));
  else if(type=="OutMiddleFloor")
    return dynamic_cast<Asset*>(dynamic_cast<MiddleFloor*>(new OutMiddleFloor()));
  else if(type=="MiddleFloorWithTwoFacades")
    return dynamic_cast<Asset*>(dynamic_cast<MiddleFloor*>(new MiddleFloorWithTwoFacades()));
  else if(type=="WorkingMiddleFloor")
    return dynamic_cast<Asset*>(dynamic_cast<MiddleFloor*>(new WorkingMiddleFloor()));
  else if(type=="WorkingMiddleFloor2")
    return dynamic_cast<Asset*>(dynamic_cast<MiddleFloor*>(new WorkingMiddleFloor2()));
  else if(type=="FactoryMiddleFloor")
    return dynamic_cast<Asset*>(dynamic_cast<MiddleFloor*>(new FactoryMiddleFloor()));
  else if(type=="FactoryTopFloor")
    return dynamic_cast<Asset*>(dynamic_cast<MiddleFloor*>(new FactoryTopFloor()));
	//else if(type=="WorkingTopFloor2")
  //  return dynamic_cast<Asset*>(dynamic_cast<TopFloor*>(new WorkingTopFloor2()));
  //--
  //--Wall
  else if(type=="BasicWallWithWindow")
    return dynamic_cast<Asset*>(dynamic_cast<WallWithWindow*>(new BasicWallWithWindow()));
  else if(type=="WallWithBigWindow")
    return dynamic_cast<Asset*>(dynamic_cast<WallWithWindow*>(new WallWithBigWindow()));
  else if(type=="BasicWall")
    return dynamic_cast<Asset*>(dynamic_cast<Wall*>(new BasicWall()));
  else if(type=="BasicWallWithDoor")
    return dynamic_cast<Asset*>(dynamic_cast<WallWithDoor*>(new BasicWallWithDoor()));
  else if(type=="GuardrailWithColumn")
    return dynamic_cast<Asset*>(dynamic_cast<Guardrail*>(new GuardrailWithColumn()));
  else if(type=="SimpleGuardrail")
    return dynamic_cast<Asset*>(dynamic_cast<Guardrail*>(new SimpleGuardrail()));
  else if(type=="WallWithStore")
    return dynamic_cast<Asset*>(dynamic_cast<WallWithWindow*>(new WallWithStore()));
  else if(type=="WallWithInBalcony")
    return dynamic_cast<Asset*>(dynamic_cast<WallWithWindow*>(new WallWithInBalcony()));
  else if(type=="WallWithWindowAndBalcony")
    return dynamic_cast<Asset*>(dynamic_cast<WallWithWindow*>(new WallWithWindowAndBalcony()));
  //--
  //--Windows--
  else if(type=="BasicFrameWindow")
    return dynamic_cast<Asset*>(dynamic_cast<FrameWindow*>(new BasicFrameWindow()));
  else if(type=="CrossWindow")
    return dynamic_cast<Asset*>(dynamic_cast<Window*>(new CrossWindow()));
  else if(type=="JailWindow")
    return dynamic_cast<Asset*>(dynamic_cast<Window*>(new JailWindow	()));
  else if(type=="BarWindow")
    return dynamic_cast<Asset*>(dynamic_cast<Window*>(new BarWindow()));
  else if(type=="SimpleWindow")
    return dynamic_cast<Asset*>(dynamic_cast<Window*>(new SimpleWindow()));
  //--
  //--Roofs--
  else if(type=="SimpleRoof")
    return dynamic_cast<Asset*>(dynamic_cast<Roof*>(new SimpleRoof()));
  else if(type=="FactoryRoof")
    return dynamic_cast<Asset*>(dynamic_cast<Roof*>(new FactoryRoof()));
  else if(type=="RoofWithChimney")
    return dynamic_cast<Asset*>(dynamic_cast<Roof*>(new RoofWithChimney()));
  else if(type=="SimpleChimney")
    return dynamic_cast<Asset*>(dynamic_cast<Chimney*>(new SimpleChimney()));
  else if(type=="FlatRoof")
    return dynamic_cast<Asset*>(dynamic_cast<Roof*>(new FlatRoof()));
  //--
  //--Balcony--
  else if(type=="SimpleBalcony")
    return dynamic_cast<Asset*>(dynamic_cast<Balcony*>(new SimpleBalcony()));
  //--
  //--Decorations--
  else if(type=="Bar")
    return dynamic_cast<Asset*>(dynamic_cast<Decoration*>(new Bar()));
  else if(type=="DecorationNull")
    return dynamic_cast<Asset*>(dynamic_cast<Decoration*>(new DecorationNull()));
  //--
  //--Doors--
  else if(type=="BasicFrameDoor")
    return dynamic_cast<Asset*>(dynamic_cast<FrameDoor*>(new BasicFrameDoor()));
  else if(type=="FrameDoorWithTriangle")
    return dynamic_cast<Asset*>(dynamic_cast<FrameDoor*>(new FrameDoorWithTriangle()));
  else if(type=="DoorWithHole")
    return dynamic_cast<Asset*>(dynamic_cast<Door*>(new DoorWithHole()));
  else if(type=="SimpleDoor")
    return dynamic_cast<Asset*>(dynamic_cast<Door*>(new SimpleDoor()));
  else if(type=="WorkingDoor")
    return dynamic_cast<Asset*>(dynamic_cast<Door*>(new WorkingDoor()));

  //--Pavements--
  else if(type=="BasicPavement")
    return dynamic_cast<Asset*>(dynamic_cast<Pavement*>(new BasicPavement()));
  //--Column--
  else if(type=="SimpleColumn")
    return dynamic_cast<Asset*>(dynamic_cast<Column*>(new SimpleColumn()));
  //--SatelliteDish--
  else if(type=="SimpleSatelliteDish")
    return dynamic_cast<Asset*>(dynamic_cast<SatelliteDish*>(new SimpleSatelliteDish()));
   //--Streetligth--
  else if(type=="SimpleStreetlight")
    return dynamic_cast<Asset*>(dynamic_cast<Streetlight*>(new SimpleStreetlight()));
  //--TrafficLigth--
  else if(type=="SimpleTrafficLight")
    return dynamic_cast<Asset*>(dynamic_cast<TrafficLight*>(new SimpleTrafficLight()));
  else if(type=="BigTrafficLight")
    return dynamic_cast<Asset*>(dynamic_cast<TrafficLight*>(new BigTrafficLight()));
  //--StreetBloc--
  else if(type=="StreetCorner")
    return dynamic_cast<Asset*>(dynamic_cast<StreetBloc*>(new StreetCorner()));
   else if(type=="StreetAlley")
    return dynamic_cast<Asset*>(dynamic_cast<StreetBloc*>(new StreetAlley()));
  else
  {
    printf("Type [%s] not avaible in factory. We can order it if u want ?\n",type.c_str());
    return NULL;
  }
}
