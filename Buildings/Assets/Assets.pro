ASSETS = Balcony Guardrail Column Chimney Roof Window Decoration Wall Door SatelliteDish WallWithWindow WallWithDoor FrameWindow FrameDoor BusStop TrafficLight Streetlight BottomFloor MiddleFloor TopFloor Building Pavement Tile StreetBloc

for(ASSET, ASSETS) {
    include($$ASSET/$$ASSET".pro")
    for(LOCAL_ASSET_HEADER_FILE, LOCAL_ASSET_HEADER_FILES) {
	ASSET_HEADER_FILES += $$ASSET/$$LOCAL_ASSET_HEADER_FILE
    }
    for(LOCAL_ASSET_SRC_FILE, LOCAL_ASSET_SRC_FILES) {
	ASSET_SRC_FILES += $$ASSET/$$LOCAL_ASSET_SRC_FILE
    }
}

ASSET_HEADER_FILES += Asset.hpp
ASSET_SRC_FILES += Asset.cpp