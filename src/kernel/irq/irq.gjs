Module("genos.irqtbl", {
	sources : {
		cc : ["do_irq.c", "irq.c", "irq_stub.c"]
	}
})