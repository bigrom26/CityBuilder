#ifndef _FACTORY_
#define _FACTORY_

#include <Asset.hpp>
#include <string>

using std::string;

//All "specified" assets must be included

#include <BasicBuilding.hpp>
#include <BasicBottomFloor.hpp>
#include <BasicFrameWindow.hpp>
#include <BasicMiddleFloor.hpp>
#include <BasicTopFloor.hpp>
#include <BasicWallWithDoor.hpp>
#include <BasicWallWithWindow.hpp>
#include <BasicWall.hpp>
#include <Bar.hpp>
#include <BottomFloorWithTwoFacades.hpp>
#include <Building.hpp>
#include <Column.hpp>
#include <CommercialBottomFloor.hpp>
#include <CrossWindow.hpp>
#include <DoorWithHole.hpp>
#include <FrameDoor.hpp>
#include <FrameDoorWithTriangle.hpp>
#include <Guardrail.hpp>
#include <GuardrailWithColumn.hpp>
#include <JailWindow.hpp>
#include <JailWindow.hpp>
#include <MiddleFloorWithTwoFacades.hpp>
#include <OutMiddleFloor.hpp>
#include <RoofWithChimney.hpp>
#include <SimpleBalcony.hpp>
#include <SimpleBusStop.hpp>
#include <SimpleChimney.hpp>
#include <SimpleColumn.hpp>
#include <SimpleGuardrail.hpp>
#include <SimpleRoof.hpp>
#include <SimpleSatelliteDish.hpp>
#include <SimpleStreetlight.hpp>
#include <SimpleWindow.hpp>
#include <SimpleDoor.hpp>
#include <SkyscraperBuilding.hpp>
#include <StreetBloc.hpp>
#include <StreetAlley.hpp>
#include <StreetCorner.hpp>
#include <Streetlight.hpp>
#include <TopFloorWithTwoFacades.hpp>
#include <TrafficLight.hpp>
#include <SimpleTrafficLight.hpp>
#include <BigTrafficLight.hpp>
#include <WallWithBigWindow.hpp>
#include <WallWithStore.hpp>
#include <WallWithWindowAndBalcony.hpp>
#include <Window.hpp>
#include <WorkingMiddleFloor2.hpp>
#include <WorkingTopFloor.hpp>
#include <WorkingDoor.hpp>
#include <WallWithInBalcony.hpp>
#include <BasicPavement.hpp>
#include <DecorationNull.hpp>
#include <BarWindow.hpp>
#include <WorkingMiddleFloor.hpp>
#include <RoofWithChimney.hpp>
#include <WallWithInBalcony.hpp>
#include <FlatRoof.hpp>
#include <FactoryRoof.hpp>
#include <FactoryMiddleFloor.hpp>
//#include <WorkingTopFloor2.hpp>
#include <FactoryTopFloor.hpp>

class Factory
{
	public :
		Factory();
		~Factory();
		Asset* getAsset(string t);//generic asset need a random choice
	private :
};

#endif
