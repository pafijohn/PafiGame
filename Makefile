.PHONY: clean All

All:
	@echo "----------Building project:[ MysteraLegends - Debug ]----------"
	@"$(MAKE)" -f  "MysteraLegends.mk"
clean:
	@echo "----------Cleaning project:[ MysteraLegends - Debug ]----------"
	@"$(MAKE)" -f  "MysteraLegends.mk" clean
