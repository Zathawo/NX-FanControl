TARGETS := lib/libfancontrol sysmodule overlay

.PHONY: all $(TARGETS)

lib/libfancontrol:
	$(MAKE) -C $@

overlay:
	$(MAKE) -C $@

sysmodule:
	$(MAKE) -C $@

all: $(TARGETS)
	mkdir -p ./out/switch/.overlays
	cp ./overlay/overlay.ovl ./out/switch/.overlays/Nx-FanControl.ovl
	
	mkdir -p ./out/atmosphere/contents/00FF0000B378D640/flags
	cp ./sysmodule/sysmodule.nsp ./out/atmosphere/contents/00FF0000B378D640/exefs.nsp
	cp ./sysmodule/toolbox.json ./out/atmosphere/contents/00FF0000B378D640/
	touch ./out/atmosphere/contents/00FF0000B378D640/flags/boot2.flag