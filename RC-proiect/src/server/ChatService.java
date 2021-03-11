package server;

import java.rmi.RemoteException;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.Random;

import static java.util.Collections.synchronizedMap; // adaugat de mine / yt

import common.IChat;
import common.IChatCallback;

public class ChatService implements IChat {

	private Map<String, IChatCallback> users = new HashMap<String, IChatCallback>();
	private int currentNumber;
	
	private void generateRandomNumber() {
        Random rand = new Random(System.currentTimeMillis());
        currentNumber = rand.nextInt((9999 - 1000) + 1) + 1000;
    }

	public ChatService(Registry registry, String name) throws RemoteException {
		registry.rebind(name, UnicastRemoteObject.exportObject(this, 0));
		generateRandomNumber();
	}

	@Override
	public void login(String name, IChatCallback callback) throws RemoteException {
		if (users.containsKey(name)) {
			callback.onDeny();
		} else {
			final List<String> names = new ArrayList<String>();
			names.add("*");
			users.entrySet().stream().forEach(entry -> {
				try {
					entry.getValue().onAddUser(name);
					names.add(entry.getKey());
				} catch (RemoteException e) {
				}
			});
			users.put(name, callback);
			callback.onAccept(names.toArray(new String[names.size()]));
		}
	}

	@Override
	public void logout(IChatCallback callback) throws RemoteException {
		final Optional<String> name = getName(callback);
		if (name.isPresent()) {
			users.remove(name.get());
			users.entrySet().forEach(entry -> {
				try {
					entry.getValue().onRemoveUser(name.get());
				} catch (RemoteException e) {
				}
			});
			callback.onExit();
		}
	}

	@Override
	public void send(String to, String message, IChatCallback callback, String nameOfClient) throws RemoteException { //
		final Optional<String> name = getName(callback);
		if (name.isPresent()) {
			users.entrySet()
				.stream()
				.filter(entry -> "*".equals(to) 
						|| entry.getKey().equals(to)
						|| entry.getValue().equals(callback))
				.forEach(entry -> {
					try {
						entry.getValue().onReceive(name.get(), message);
					} catch (RemoteException e) {
					}
				});
		}

		System.out.println(name.get() + " is guessing...");
		if(message.length() <= 3 || message.length() >= 5)
        {
        	System.out.println("Wrong input by " + name.get() + "!");
            return;
        }
		
		String answer = updateAnswer(Integer.parseInt(message.trim()));
		int centeredPositions = findCentered(Integer.parseInt(message.trim()));
        int uncenteredPositions = findUncentered(Integer.parseInt(message.trim()));
        System.out.println("Centered numbers: " + centeredPositions);
        System.out.println("Uncentered numbers: " + Math.abs(uncenteredPositions - centeredPositions));

        int wrongNumbers = 0;
        for(int i=0; i < answer.length() - 1; i++)
        {
            if(answer.substring(i, i+1).equals("*"))
            {
            	wrongNumbers++;
            }
        }
        if(wrongNumbers == 0)
        {
            announceWinner(name.get());
        }
        System.out.println("Insert a number between 1000 and 9999!");
		
	}
	
	private Optional<String> getName(IChatCallback callback) {
		return users.entrySet()
				.stream()
				.filter(entry -> entry.getValue().equals(callback))
				.map(entry -> entry.getKey())
				.findAny();
	}
	
	private void announceWinner(String nameOfWinner) throws RemoteException
    {
        synchronized(users) 
        {
            for(IChatCallback user : users.values()) //
            {
                user.onReceive("Server", nameOfWinner + " has won!"); //
                user.onReceive("Server", "New number has been generated! Guess away!");
                user.onReceive("Server", "Insert a number between 1000 and 9999!");
            }    
        }
        System.out.println("Winner: " + nameOfWinner);
        System.out.println("New number has been generated! Guess away!");
        generateRandomNumber();
    }
    
    private int findUncentered(int number)
    {
        List<Integer> listC = new ArrayList<Integer>();
        List<Integer> listN = new ArrayList<Integer>();
        
        int uncenteredNumbers = 0;
        int tmpCurrentNumber = currentNumber;
        while(tmpCurrentNumber != 0)
        {
            int lCurrent = tmpCurrentNumber % 10;
            int lNumber = number % 10;
            listC.add(lCurrent);
            listN.add(lNumber);
            tmpCurrentNumber /= 10;
            number /= 10;
        }
        
        for(int i = 0; i < listC.size(); i++)
            for(int j = 0; j < listN.size(); j++)
            {
                if(listC.get(i) == listN.get(j))
                {
                	uncenteredNumbers++;
                    listN.set(i, -1);
                }
            }
        
        return uncenteredNumbers;
    }
    
    private int findCentered(int number)
    {
        int centeredNumbers = 0;
        int tmpCurrentNumber = currentNumber;
        while(number != 0)
        {
            int lCurrent = tmpCurrentNumber % 10;
            int lNumber = number % 10;
            if(lCurrent == lNumber)
            {
            	centeredNumbers++;
            }
  
            number /= 10;
            tmpCurrentNumber /= 10;
        }
        
        return centeredNumbers;
    }
    
    private String updateAnswer(int number)
    {
        String answer = "";
        int tmpCurrentNumber = currentNumber;
        while(number != 0)
        {
            int lCurrent = tmpCurrentNumber % 10;
            int lNumber = number % 10;
            if(lCurrent == lNumber)
            {
                answer += lCurrent;
            }
            else
            {
                answer += "*";
            }
            number /= 10;
            tmpCurrentNumber /= 10;
        }
        
        StringBuilder answerReverse = new StringBuilder();
        answerReverse.append(answer);
        answerReverse.reverse();
        
        System.out.println("Answer: " + answerReverse);
        
        return new StringBuilder(answer).reverse().toString();
    }

}
