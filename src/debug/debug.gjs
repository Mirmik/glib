Implementation("genos.dprint", "stub", {
	sources : {
		cc : ["dprint_func_stub.c", "dprint_stub.c"]
	}
})

Implementation("genos.dprint", "diag", {
	sources : {
		cc : ["dprint_func_impl.c", "dprint_diag.c", "assembler.c"],
		cxx : ["dprintxx.cpp"],
	},

	options : {
		cc : ["-Wno-pointer-to-int-cast"],
	},

	depends : ["genos.diag"],
})

Implementation("genos.dprint", "manually", {
	sources : {
		cc : ["dprint_func_impl.c", "dprint_manually.c", "assembler.c"],
		cxx : ["dprintxx.cpp"],
	}
})
