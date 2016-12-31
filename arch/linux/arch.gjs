Module("genos.include.arch.linux32", {
	opts : {
		includePaths : ["./include", "./linux32/include"]
	},
	modules : [{name : "genos.arch.linux"}]
})

Module("genos.include.arch.linux64", {
	opts : {
		includePaths : ["./include", "./linux64/include"]
	},
	modules : [{name : "genos.arch.linux"}]
})

Module("genos.arch.linux", {
	sources : {
		cc : ["asm/arch.c", "asm/diag.c"]
	},
	opts : {
		options : { 
			cc : ["-Wno-incompatible-pointer-types"], 
		}
	} 
})