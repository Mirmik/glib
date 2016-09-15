#ifndef GENOS_NAMESPACE
#define GENOS_NAMESPACE

#include <gxx/DList.h>
#include <gxx/ByteArray.h>
#include <string.h>
//#include <datastruct/tree.h>

namespace Kernel {

	class NamedObject {
	public:
		enum Type {
			NOTYPE_NAMESPACE,
			NOTYPE_JUSTNAME,	
		};

	public:
		dlist_head 			lnk;

		Type 				type;
		const char* 		name;

		NamedObject(const char* _name) : name(_name), type(NOTYPE_JUSTNAME) {
			dlist_init(&lnk);
		};

		NamedObject(const char* _name, Type _type) : name(_name), type(_type) {
			dlist_init(&lnk);
		};
	};

	class NameSpace : public NamedObject {
	public:
		gxx::DList<NamedObject, &NamedObject::lnk> childs;

		NameSpace(const char* _name) : childs(), NamedObject(_name, NamedObject::NOTYPE_NAMESPACE) {};

		NamedObject* find(const char* target) {
			auto begin = childs.begin();
			auto end = childs.end();
			for (auto it = begin; it != end; ++it) {
				if (!strcmp(it->name, target)) return &*it;
			}
			return nullptr;
		}

		void addObject(NamedObject* obj) {
			childs.push_back(*obj);
		}

		gxx::string to_str() const {
			gxx::string str;
			str.reserve(128);
			for(auto r : childs) {
				str << r.name << "\r\n";
			}
			return str;
		}
	};

	extern NameSpace rootNameSpace;

};

#endif