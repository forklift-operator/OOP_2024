#include <iostream>
#include <fstream>

const size_t SIZE = 15;

const char *Suit_arr[SIZE] = {"♡", "♦️", "♣️", "♠️"};
const char *Color_arr[SIZE] = {"🟥", "⬛"};

const char *Suit_arr1[SIZE] =
    {
        "hearts",
        "diamonds",
        "clubs",
        "spades"};

const char *Suit_arr11[SIZE] =
    {
        "h",
        "d",
        "c",
        "s"};

const char *Color_arr1[SIZE] =
    {
        "red",
        "black"};

const char *Color_arr11[SIZE] =
    {
        "r",
        "b"};

const char *Honor_arr[SIZE] =
    {
        "A",
        "K",
        "Q",
        "J"};

enum Suit
{
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
};
enum Color
{
    RED,
    BLACK
};
const char *Rank_arr[18] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
// enum Rank {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, J, Q, K, A};
enum Honor
{
    A,
    K,
    J,
    Q
};

enum NumOrPic
{
    NUM,
    PIC
};

struct Card
{
    Suit s;
    Color c;
    union
    {
        int num;
        Honor rank;
    };
    NumOrPic num_or_pic;
};

struct Player
{
    Card cards[13];
};

const Card deck[52] =
    {
        {HEARTS, RED, 2}, {HEARTS, RED, 3}, {HEARTS, RED, 4}, {HEARTS, RED, 5}, {HEARTS, RED, 6}, {HEARTS, RED, 7}, {HEARTS, RED, 8}, {HEARTS, RED, 9}, {HEARTS, RED, 10}, {HEARTS, RED, J}, {HEARTS, RED, Q}, {HEARTS, RED, K}, {HEARTS, RED, A}, {DIAMONDS, RED, 2}, {DIAMONDS, RED, 3}, {DIAMONDS, RED, 4}, {DIAMONDS, RED, 5}, {DIAMONDS, RED, 6}, {DIAMONDS, RED, 7}, {DIAMONDS, RED, 8}, {DIAMONDS, RED, 9}, {DIAMONDS, RED, 10}, {DIAMONDS, RED, J}, {DIAMONDS, RED, Q}, {DIAMONDS, RED, K}, {DIAMONDS, RED, A}, {CLUBS, BLACK, 2}, {CLUBS, BLACK, 3}, {CLUBS, BLACK, 4}, {CLUBS, BLACK, 5}, {CLUBS, BLACK, 6}, {CLUBS, BLACK, 7}, {CLUBS, BLACK, 8}, {CLUBS, BLACK, 9}, {CLUBS, BLACK, 10}, {CLUBS, BLACK, J}, {CLUBS, BLACK, Q}, {CLUBS, BLACK, K}, {CLUBS, BLACK, A}, {SPADES, BLACK, 2}, {SPADES, BLACK, 3}, {SPADES, BLACK, 4}, {SPADES, BLACK, 5}, {SPADES, BLACK, 6}, {SPADES, BLACK, 7}, {SPADES, BLACK, 8}, {SPADES, BLACK, 9}, {SPADES, BLACK, 10}, {SPADES, BLACK, J}, {SPADES, BLACK, Q}, {SPADES, BLACK, K}, {SPADES, BLACK, A}};

bool usedCard(int *used_cards, int index_of_card, int num_of_cards_in_deck)
{
    for (size_t i = 0; i < num_of_cards_in_deck; ++i)
    {
        if (used_cards[i] == index_of_card)
        {
            return true;
        }
    }
    return false;
}

void distributeCards(const Card *deck, Player *player, int numOfPlayers, int num_of_cards_in_deck, int num_of_cards_to_player)
{
    std::ofstream file("cards.txt");
    if (!file.is_open())
    {
        std::cout << "Error";
    }

    int used_cards[num_of_cards_in_deck];
    size_t k = 0;
    for (size_t i = 0; i < numOfPlayers; ++i)
    {
        // std::cout << "\n" << "player " << i + 1 << ": ";
        file << "\nplayer " << i + 1 << ": ";

        for (size_t j = 0; j < num_of_cards_to_player; ++j)
        {
            // int rand_index = std::rand() % num_of_cards_in_deck + 1;
            // while(!usedCard(used_cards, rand_index)){
            //     rand_index = rand() % num_of_cards_in_deck + 1;
            //     used_cards[k+j] = rand_index;
            //     break;
            // }

            std::srand(time(0));
            int rand_index;
            do
            {
                rand_index = std::rand() % num_of_cards_in_deck;
            } while (usedCard(used_cards, rand_index, num_of_cards_in_deck));

            used_cards[k + j] = rand_index;

            player[i].cards[j] = deck[rand_index];

            if (rand_index % 13 >= 9 && rand_index % 13 <= 12)
            {
                player[i].cards[j].num_or_pic = PIC;
            }
            else
                player[i].cards[j].num_or_pic = NUM;

            if (player[i].cards[j].num_or_pic == PIC)
            {

                // std::cout << "|" << Honor_arr[player[i].cards[j].rank] << Suit_arr[player[i].cards[j].s] << Color_arr[player[i].cards[j].c] << "| ";
                file << "|" << Honor_arr[player[i].cards[j].rank] << Suit_arr[player[i].cards[j].s] << Color_arr[player[i].cards[j].c] << "| ";
            }
            else
            {
                // std::cout << "|" << player[i].cards[j].num << Suit_arr[player[i].cards[j].s] << Color_arr[player[i].cards[j].c] << "| "; // SOMETIMES WORKS BUT LOOKS BETTER
                file << "|" << player[i].cards[j].num << Suit_arr[player[i].cards[j].s] << Color_arr[player[i].cards[j].c] << "| ";
            }

            // std::cout << "|" << Suit_arr[player[i].cards[j].s] << Color_arr[player[i].cards[j].c] << "(" << rand_index + 1 << ")"<< "| "; // WORKS
        }

        // std::cout << "\n";

        k += num_of_cards_to_player;
    }
    file.close();
}

void PrintSpecificPlayerCards(Player &player, int num_of_cards)
{
    for (size_t i = 0; i < num_of_cards; ++i)
    {
        if (player.cards[i].num_or_pic == PIC)
        {

            std::cout << "|" << Honor_arr[player.cards[i].rank] << Suit_arr[player.cards[i].s] << Color_arr[player.cards[i].c] << "| ";
        }
        else
            std::cout << "|" << player.cards[i].num << Suit_arr[player.cards[i].s] << Color_arr[player.cards[i].c] << "| ";
    }
}

int main()
{
    size_t num_of_players, num_of_cards_to_player;
    std::cout << "Number of players: ";
    std::cin >> num_of_players;
    std::cout << "Number of cards to player: ";
    std::cin >> num_of_cards_to_player;

    Player *players = new Player[num_of_players];

    distributeCards(deck, players, num_of_players, 52, num_of_cards_to_player);
    std::cout << "\n\n";

    // PrintSpecificPlayerCards(players[1], 10);
    std::cout << "\nSaved in cards.txt!";

    return 0;
}
