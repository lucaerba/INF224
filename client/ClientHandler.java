public class ClientHandler {
    private Client client;

    public ClientHandler() {
        // Initialize the Client
        try {
            client = new Client("localhost", 3331); // Use the correct host and port
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public String searchMedia(String query) {
        return client.send("SEARCHMEDIA " + query);
    }
    public String searchGroup(String query) {
        return client.send("SEARCHGROUP " + query);
    }

    public String play(String multimediaObjectName) {
        return client.send("PLAY " + multimediaObjectName);
    }

    public String display(String multimediaObjectName) {
        return client.send("DISPLAY " + multimediaObjectName);
    }
}
