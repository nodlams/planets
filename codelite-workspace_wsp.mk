.PHONY: clean All

All:
	@echo ----------Building project:[ Planets - Release ]----------
	@"$(MAKE)" -f "Planets.mk"
clean:
	@echo ----------Cleaning project:[ Planets - Release ]----------
	@"$(MAKE)" -f "Planets.mk" clean
