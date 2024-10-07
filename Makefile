.PHONY: clean All

All:
	@echo "----------Building project:[ GammaCiper - Debug ]----------"
	@cd "GammaCiper" && "$(MAKE)" -f  "GammaCiper.mk"
clean:
	@echo "----------Cleaning project:[ GammaCiper - Debug ]----------"
	@cd "GammaCiper" && "$(MAKE)" -f  "GammaCiper.mk" clean
