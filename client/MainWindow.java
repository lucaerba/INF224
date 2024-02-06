import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;

public class MainWindow extends JFrame {

    private static final long serialVersionUID = 1L;

    private JTextArea textArea;
    private ClientHandler clientHandler; // Use ClientHandler for client-server interaction

    public MainWindow() {
        // Set up the main window
        setTitle("Main Window");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // Initialize the ClientHandler
        clientHandler = new ClientHandler();

        // Create JTextArea with scrollbars
        textArea = new JTextArea(10, 30);
        JScrollPane scrollPane = new JScrollPane(textArea);


        AbstractAction exitAction = new AbstractAction("Exit") {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        };
        AbstractAction searchMediaAction = new AbstractAction("SearchMedia") {
            @Override
            public void actionPerformed(ActionEvent e) {
                String searchQuery = JOptionPane.showInputDialog(MainWindow.this, "Enter search query:");
                if (searchQuery != null) {
                    String response = clientHandler.searchMedia(searchQuery);
                    String[] results = response.split(",");

                    // Print the results without printing the similarity
                    for (String result : results) {
                        if(!result.contains("SEARCH_RESULT:"))
                            textArea.append("\t" + result.trim() + "\n");
                        else{
                            String[] subres = result.split(" ");
                            textArea.append(subres[0].trim() + "\n");
                            if (subres.length == 2)
                                textArea.append("\t" + subres[1].trim() + "\n");
                        }
                    }
                }
            }
        };

        AbstractAction searchGroupAction = new AbstractAction("SearchGroup") {
            @Override
            public void actionPerformed(ActionEvent e) {
                String searchQuery = JOptionPane.showInputDialog(MainWindow.this, "Enter search query:");
                if (searchQuery != null) {
                    String response = clientHandler.searchGroup(searchQuery);
                    String[] results = response.split(",");

                    // Print the results without printing the similarity
                    for (String result : results) {
                        if(!result.contains("SEARCH_RESULT:"))
                            textArea.append("\t" + result.trim() + "\n");
                        else{
                            String[] subres = result.split(" ");
                            textArea.append(subres[0].trim() + "\n");
                            if (subres.length == 2)
                                textArea.append("\t" + subres[1].trim() + "\n");
                        }
                    }
                }
            }
        };

        // Create new actions for client-server interaction
        AbstractAction displayAction = new AbstractAction("Display") {
            @Override
            public void actionPerformed(ActionEvent e) {
                String searchQuery = JOptionPane.showInputDialog(MainWindow.this, "Enter search query:");
                if (searchQuery != null) {
                    String response = clientHandler.display(searchQuery);
                    String[] results = response.split(" ");

                    // Print the results without printing the similarity
                    for (String result : results) {
                        if(!result.equals("DISPLAY_RESULT:"))
                            textArea.append("\t" + result.trim() + "\n");
                        else
                            textArea.append(result.trim() + "\n");
                    }
                }
            }
        };

        AbstractAction playAction = new AbstractAction("Play") {
            @Override
            public void actionPerformed(ActionEvent e) {
                String playQuery = JOptionPane.showInputDialog(MainWindow.this, "Enter multimedia object name:");
                if (playQuery != null) {
                    String response = clientHandler.play(playQuery);
                    textArea.append(response + "\n");
                }
            }
        };
        // Create menu bar
        JMenuBar menuBar = new JMenuBar();

        // Create drop-down menu
        JMenu fileMenu = new JMenu("File");
        fileMenu.addSeparator();
        fileMenu.add(new JMenuItem(exitAction));
        // Add new actions to menu and toolbar
        fileMenu.add(new JMenuItem(searchMediaAction));
        fileMenu.add(new JMenuItem(searchGroupAction));
        fileMenu.add(new JMenuItem(playAction));
        fileMenu.add(new JMenuItem(displayAction));
        // Add drop-down menu to menu bar
        menuBar.add(fileMenu);

        // Set menu bar to the main window
        setJMenuBar(menuBar);

        // Create toolbar
        JToolBar toolBar = new JToolBar();
        toolBar.setFloatable(false); // Make toolbar not floatable

        // Add buttons to the toolbar
        toolBar.add(new JButton(searchMediaAction));
        toolBar.add(new JButton(searchGroupAction));
        toolBar.add(new JButton(playAction));
        toolBar.add(new JButton(displayAction));
        toolBar.addSeparator();
        toolBar.add(new JButton(exitAction));

        // Set layout and add components to the frame
        setLayout(new BorderLayout());
        add(toolBar, BorderLayout.NORTH);
        add(scrollPane, BorderLayout.CENTER);

        // Pack and set visibility
        pack();
        setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new MainWindow();
            }
        });
    }
}
