#ifndef GXX_TUPLE_H
#define GXX_TUPLE_H

namespace gxx {

	template <typename T> class TupleBase {
	public:
		T data;
		TupleBase(const T& value) : data(value) {};
		T baseValue() const {return data;};
	}; 

	template <typename Head, typename ... Tail>
	class Tuple : public Tuple<Tail ...>, public TupleBase<Head> {
	public:
		using Parent = Tuple<Tail...>;
		using Base = TupleBase<Head>;
	
		//Tuple2() : Parent(), top() {}
		Tuple(Head head, Tail ... tail) : Parent(tail ...), Base(head) {}

		Head value() const {return baseValue();};
	};
	
	template <typename Head>
	class Tuple <Head> : public TupleBase<Head> {
		using Base = TupleBase<Head>;
	public:	
		//Tuple2() : top() {};
		Tuple(Head head) : Base(head) {};
		Head value() const {return baseValue();};
	};



/*


	template <typename Head, typename ... Tail>
	class Tuple : public Tuple<Tail ...> {
	public:
		using Parent = Tuple<Tail...>;

		Head top;
	
		Tuple() : Parent(), top() {}
		Tuple(Head head, Tail ... tail) : Parent(tail ...), top(head) {}

		template<typename TupleType>
		void assign (const TupleType& other) { 
			top = other.top; 
			Parent::assign(static_cast<typename TupleType::Parent>(other)); 
		}
	};
	
	template <typename Head>
	class Tuple <Head> {
	public:
		Head top;
	
		Tuple() : top() {};
		Tuple(Head head) : top(head) {};

		template<typename TupleType>
		void assign (const TupleType& other) { top = other.top; }
	};
	
*/	


	template <int Index, typename Head, typename ... Tail>
	class GetImpl {
	public:
		static auto value(const Tuple<Head,Tail...> &t) -> decltype(GetImpl<Index - 1, Tail...>::value(t)) {
			return GetImpl<Index - 1, Tail...>::value(t);
		}
	};
	
	template <typename Head, typename ... Tail>
	class GetImpl<0,Head,Tail...> {
	public:
		static Head value(const Tuple<Head,Tail...> &t) {
			return t.value();
		}
	};
	
	template <int Index, typename Head, typename ... Tail>
	auto get(const Tuple<Head,Tail...>& t) -> decltype(GetImpl<Index,Head,Tail...>::value(t)) {
		return GetImpl<Index,Head,Tail...>::value(t);
	}	
	



	/*template<typename Head, typename ... Tail>
	class Tie : public Tie<Tail...> {
	public:
		Head& top;

		Tie(Head& head, Tail& ... tail) : top(head), Tie<Tail...>(tail ...) {}
	};

	template<typename Head>
	class Tie <Head> {
	public:
		Head& top;

		Tie(Head& head) : top(head) {}
	};*/

	template <typename ... Args>
	Tuple<Args&...> tie (Args& ... args) {
		return Tuple<Args&...>(args...);
	}

};

#endif