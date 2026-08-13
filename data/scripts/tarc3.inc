LastTalkedWalkInPlaceNorth::
	applymovement VAR_0x8000, FastWalkInPlaceNorth
	return

LastTalkedWalkInPlaceSouth::
	applymovement VAR_0x8000, FastWalkInPlaceSouth
	return

LastTalkedWalkInPlaceEast::
	applymovement VAR_0x8000, FastWalkInPlaceEast
	return

LastTalkedWalkInPlaceWest::
	applymovement VAR_0x8000, FastWalkInPlaceWest
	return

FastWalkInPlaceNorth::
	walk_in_place_faster_up
	step_end

FastWalkInPlaceSouth::
	walk_in_place_faster_down
	step_end

FastWalkInPlaceEast::
	walk_in_place_faster_right
	step_end

FastWalkInPlaceWest::
	walk_in_place_faster_left
	step_end
