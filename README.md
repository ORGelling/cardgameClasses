# Card Game Project

## Overview
This project is a simple card game implemented in C++. It utilizes object-oriented programming principles to manage the game's components, including decks of cards and player hands.

## Project Structure
The project is organized into the following files and directories:

```
cardgame
├── src
│   ├── main.cpp       # Entry point of the application
│   ├── deck.h         # Header file for the Deck class
│   ├── deck.cpp       # Implementation of the Deck class
│   ├── hand.h         # Header file for the Hand class
│   ├── hand.cpp       # Implementation of the Hand class
│   └── card.h         # Definition of the Card structure
├── CMakeLists.txt     # CMake configuration file
└── README.md          # Project documentation
```

## Setup Instructions
1. **Clone the repository**:
   ```
   git clone <repository-url>
   cd cardgame
   ```

2. **Build the project**:
   - Ensure you have CMake installed.
   - Create a build directory:
     ```
     mkdir build
     cd build
     ```
   - Run CMake to configure the project:
     ```
     cmake ..
     ```
   - Build the project:
     ```
     make
     ```

3. **Run the application**:
   After building, you can run the application from the build directory:
   ```
   ./cardgame
   ```

## Gameplay
- The game initializes by creating a deck of cards and a player's hand.
- Players can draw cards from the deck and manage their hands.
- The game logic includes scoring and determining the winner based on the rules defined in the implementation.

## Contributing
Feel free to contribute to this project by submitting issues or pull requests. Your feedback and contributions are welcome!