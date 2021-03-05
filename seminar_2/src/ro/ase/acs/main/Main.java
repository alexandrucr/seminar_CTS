package ro.ase.acs.main;

import ro.ase.acs.contracts.Writeable;
import ro.ase.acs.readers.Reader;
import ro.ase.acs.writers.ConsoleWriter;
import java.lang.reflect.*;

public class Main {

	public static void main(String[] args) throws InstantiationException, IllegalAccessException {
		
		IoC ioc = new IoC();
		ioc.register(Readable.class, Reader.class);
		ioc.register(Writeable.class, ConsoleWriter.class);
		
		Reader reader = (Reader) ioc.resolve(Readable.class).newInstance();
		ConsoleWriter writer = (ConsoleWriter) ioc.resolve(Writeable.class).newInstance();
		
		Orchestrator orchestrator = new Orchestrator(reader, writer);
		orchestrator.execute();
		

	}

}
