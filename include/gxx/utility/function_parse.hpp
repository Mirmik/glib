

template<typename Function> 
struct signature;

template<typename Ret, typename Arg> 
struct signature<Ret(*)(Arg)> {
	using ret_type = Ret;
	using arg_type = Arg;
	using func_type = Ret(*)(Arg);
};