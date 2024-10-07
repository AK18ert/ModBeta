.PHONY: clean All

All:
	@echo "----------Building project:[ ModBeta - Debug ]----------"
	@cd "ModBeta" && "$(MAKE)" -f  "ModBeta.mk"
clean:
	@echo "----------Cleaning project:[ ModBeta - Debug ]----------"
	@cd "ModBeta" && "$(MAKE)" -f  "ModBeta.mk" clean
