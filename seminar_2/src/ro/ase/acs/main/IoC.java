package ro.ase.acs.main;

import java.util.HashMap;
import java.util.Map;

public class IoC {
	private Map<Class<?>, Class<?>> map = new HashMap<>();
	//
	private Class<?> clasa;
	
	public void register(Class<?> contract, Class<?> implementation) {
		if(!map.containsKey(contract)) {
			map.put(contract, implementation);
		}
	}
	
	public Class<?> resolve(Class<?> contract) {
		if(map.containsKey(contract)) {
			return map.get(contract);
		}
		return null;
	}
}
