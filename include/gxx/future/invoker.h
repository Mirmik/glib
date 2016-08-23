#ifndef GXX_INVOKER_H
#define GXX_INVOKER_H

//#include <tuple>
#include <gxx/future/archive.h>

namespace gxx {

	template<typename InputArchive, typename OutputArchive>
	class ArchiveInvokerBasic {
	public:
		void *func;
		ArchiveInvokerBasic(void* _f) : func(_f) {};

		virtual uint8_t invoke(InputArchive&, OutputArchive&) = 0;
	};

	template<typename InputArchive>
	class NoRetArchiveInvokerBasic {
	public:
		void *func;
		NoRetArchiveInvokerBasic(void* _f) : func(_f) {};

		virtual uint8_t invoke(InputArchive&) = 0;
	};

	template <typename Ret, typename Arg, typename InputArchive, typename OutputArchive>
	class ArchiveInvoker : public ArchiveInvokerBasic<InputArchive, OutputArchive> {
	public:
		ArchiveInvoker(void* _f) :ArchiveInvokerBasic<InputArchive, OutputArchive>(_f) {};
		ArchiveInvoker(const ArchiveInvoker& other) : ArchiveInvokerBasic<InputArchive, OutputArchive>(other.func) {};

		uint8_t invoke(InputArchive& inar, OutputArchive& outar) {
			Arg  arg;
			gxx::load(arg,inar);
			Ret ret = ((Ret(*)(Arg))ArchiveInvokerBasic<InputArchive, OutputArchive>::func)(arg);
			gxx::save(ret,outar);
			return 0;
		}
	};

	template <typename Arg, typename InputArchive>
	class NoRetArchiveInvoker : public NoRetArchiveInvokerBasic<InputArchive> {
	public:
		NoRetArchiveInvoker(void* _f) : NoRetArchiveInvokerBasic<InputArchive>(_f) {};
		NoRetArchiveInvoker(const NoRetArchiveInvoker& other) : NoRetArchiveInvokerBasic<InputArchive>(other.func) {};

		uint8_t invoke(InputArchive& inar) {
			Arg  arg;
			gxx::load(arg,inar);
			((void(*)(Arg))NoRetArchiveInvokerBasic<InputArchive>::func)(arg);
			return 0;
		}
	};
}

#endif