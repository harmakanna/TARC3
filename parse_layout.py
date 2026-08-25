import os
import json

test = {
	"frlg_border":[],
	"frlg_map":[],
	"emerald_border":[],
	"emerald_map":[],
	}

with open("data/layouts/layouts.json", "r") as f:
	data = json.load(f)
	for layout in data["layouts"]:
		if ("layout_version" in layout and layout["layout_version"] == "frlg") or layout["name"] == "SilphCo_1F_Layout":
			test["frlg_border"].append(layout["border_filepath"])
			test["frlg_map"].append(layout["blockdata_filepath"])
		elif "layout_version" in layout and layout["layout_version"] == "emerald":
			test["emerald_border"].append(layout["border_filepath"])
			test["emerald_map"].append(layout["blockdata_filepath"])

with open("layouts.tmp", "w+") as f:
	json.dump(test, f)