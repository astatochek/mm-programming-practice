#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <cstring>
#include <ctype.h>

using namespace std;




bool IsNumber(string s){
    for (int i = 0; i < s.length(); i++){
        if (!isdigit(s[i])) return false;
    }
    return true;
}

class card
{
public:
    string suit;
    string name;
    int value;
    card(string name_, string suit_, int value_)
    {
        suit = std::move(suit_);
        name = std::move(name_);
        value = value_;
    }
};


class deck: public card
{
public:
    deck();

    deck(string name, string suit, int value, string name_, string suit_, int value_);

    ~deck();
    void Push(card card_);
    card Pop();
    bool isEmpty();
    void Print();
private:
    struct Node {
        string suit;
        string name;
        int value;
        Node *p;
    };

    Node *top;
};

deck::deck(string name, string suit, int value, string name_, string suit_, int value_) : card(name, suit, value) {}

void deck::Push(card card_) {
    Node *pv = new Node;
    pv->name = card_.name;
    pv->value = card_.value;
    pv->suit = card_.suit;
    pv->p = top;
    top = pv;
}

card deck::Pop() {
    if (isEmpty()) {
        return card("0", "0", 0);
    }

    card temp = card(top->name, top->suit, top->value);
    Node *pv = top;
    top = top->p;
    delete pv;
    return temp;
}

bool deck::isEmpty() {
    return top ? false : true;
}

deck::~deck() {
    while (top) {
        Node *pv = top;
        top = top->p;
        delete pv;
    }
}

void shuffle_this(vector <card> &pre_deck)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::shuffle(std::begin(pre_deck), std::end(pre_deck), e);
};

class turn
{
public:
    vector <string> stage = {"your go", "opponent blocks", "your additions", "your result", "opponent go", "your blocks", "opponent additions",
                             "opponent result"};
    int index = -1;
    string current_stage;
    void next(int i=1)
    {
        index = index + i;
        current_stage = stage[index%stage.size()];
    }
};

bool cmp(card first, card second)
{
    return first.value <= second.value;
}


class player_hand
{
public:
    vector <card> data;
    void add(card card_)
    {
        data.push_back(card_);
    }
    void discard(int i)
    {
        data.erase(data.begin()+i);
    }
    player_hand(vector <card> vec_ = {})
    {
        data = vec_;
    }
    card& operator[](int i)
    {
        return data[i];
    }
    void sort()
    {
        ::sort(data.begin(), data.end(), cmp);
    }
};


void show(vector <card> hand)
{
    cout << "--> Your hand:\n";
    for (int _ = 0; _ < hand.size(); _++) cout << _+1 << ": " << hand[_].name << "\n";
    cout << "\n";
}

void show(vector <vector<card>> field)
{
    cout << "--> Current field:\n";
    for (int _ = 0; _ < field.size(); _++)
    {
        cout << field[_][0].name << " < ";
        if (field[_][1].value == 0) cout << "_____\n";
        else cout << field[_][1].name << "\n";
    }
    cout << "\n";
}



int main()
{
    vector <card> new_deck;
    vector <card> dumpster;
    string tmp_name;
    vector <string> suits = {"clubs", "spades", "hearts", "diamonds"};
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::shuffle(std::begin(suits), std::end(suits), e);
    string trump = suits[0];
    card temp = card("0", "0", 0);
    vector <string> names = {"6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    for (int i = 6; i < 6 + names.size(); i++){
        for (int j = 0; j < suits.size(); j++){
            tmp_name = names[i-6] + " of " + suits[j];
            temp.name = tmp_name;
            temp.suit = suits[j];
            temp.value = suits[j] == trump ? i+14 : i;
            new_deck.push_back(temp);
        }
    }
    cout << "--> Deck created\n\n";
    shuffle_this(new_deck);
    cout << "--> Deck shuffled\n\n";
    deck game_deck = deck("0", "0", 0, "0", "0", 0);
    for (int i = 0; i < new_deck.size(); i++) game_deck.Push(new_deck[i]);
    cout << "--> Deck ready\n\n";

    /*
    card card_ = card("1", "0", 0);
    while (!game_deck.isEmpty()){
        card_ = game_deck.Pop();
        cout << card_.name << "; ";
    }
     */

    cout << "--> START!\n\n";
    cout << "--> " << trump << " are trumps\n\n";
    turn iter_turn;
    iter_turn.next();
    player_hand your_hand;
    player_hand opponent_hand;
    for (int _ = 0; _ < 6; _++)
    {
        your_hand.add(game_deck.Pop());
        opponent_hand.add(game_deck.Pop());
    }
    show(your_hand.data);
    vector <vector<card>> field;
    /*field.push_back({your_hand[0], card("0", "0", 0)});
    show(field);*/
    bool check;
    bool flag;
    bool ONGOING = true;
    string command;
    sort(opponent_hand.data.begin(), opponent_hand.data.end(), cmp);
    //show(opponent_hand);




    while(ONGOING)
    {
        /*cout << "info:\n";
        show(your_hand.data);
        show(opponent_hand.data);
        show(dumpster);
        cout << "end of info\n\n";*/
        if (iter_turn.current_stage == "your go")
        {
            check = true;
            cout << "--> Make a play!\n\n";
            int index;
            string index_;
            while (check)
            {
                cout << "(to play a card first type 'play')\n";
                cin >> command;
                if (command == "play")
                {
                    cout << "--> " << trump << " are trumps\n";
                    cout << "--> Opponent's hand size: " << opponent_hand.data.size() << "\n\n";
                    show(your_hand.data);
                }
                else
                {
                    cout << "--> Wrong Command!!\n";
                    continue;
                }
                cout << "(type the index of a card you want to play)\n";
                cin >> index_;

                if (IsNumber(index_) && stoi(index_) >= 1 && stoi(index_) <= your_hand.data.size())
                {
                    index = stoi(index_);
                    index-=1;
                    field.push_back({your_hand[index], card("0", "0", 0)});
                    show(field);
                    your_hand.discard(index);
                    check = false;
                    iter_turn.next();
                }
                else
                {
                    cout << "--> Wrong Command!!\n";
                    continue;
                }
            }
        }

        if (iter_turn.current_stage == "opponent blocks")
        {
            for (int i = 0; i < opponent_hand.data.size(); i++)
            {
                if ((field[field.size()-1][0].suit == opponent_hand[i].suit ||  opponent_hand[i].suit == trump)
                && field[field.size()-1][0].value < opponent_hand[i].value)
                {
                    field[field.size()-1][1] = opponent_hand[i];
                    opponent_hand.discard(i);
                    show(field);
                    if (opponent_hand.data.size() == 0) iter_turn.next(2);
                    else iter_turn.next();
                    break;
                }
            }
            if (field[field.size()-1][1].value == 0)
            {
                iter_turn.next(2);
            }
        }

        if (iter_turn.current_stage == "your additions")
        {
            cout << "--> Your move!\n\n";
            check = true;
            int index;
            string index_;
            while (check)
            {
                cout << "(to play a card first type 'play')\n";
                cout << "(if you don't want to play cards type 'end')\n";
                cin >> command;
                if (command == "play" && opponent_hand.data.size() != 0){
                    flag = false;
                    cout << "--> " << trump << " are trumps\n";
                    cout << "--> Opponent's hand size: " << opponent_hand.data.size() << "\n\n";
                    show(your_hand.data);
                    cout << "(type the index of a card you want to play)\n";
                    cin >> index_;

                    if (IsNumber(index_) && stoi(index_) >= 1 && stoi(index_) <= your_hand.data.size())
                    {
                        index = stoi(index_);
                        index-=1;
                        int tmp_value = your_hand[index].value;
                        if (tmp_value > 14) tmp_value -= 14;
                        for (int i = 0; i < field.size(); i++)
                        {
                            if (tmp_value == field[i][0].value || tmp_value == field[i][0].value - 14) flag = true;
                            if (tmp_value == field[i][1].value || tmp_value == field[i][1].value - 14) flag = true;
                        }
                        if (flag)
                        {
                            field.push_back({your_hand[index], card("0", "0", 0)});
                            show(field);
                            your_hand.discard(index);
                            check = false;
                            iter_turn.next(-1);
                        }
                        else
                        {
                            cout << "--> Wrong Command!!\n";
                            continue;
                        }
                    }
                    else
                    {
                        cout << "--> Wrong Command!!\n";
                        continue;
                    }
                }
                else if (command == "end")
                {
                    check = false;
                    iter_turn.next();
                }
                else
                {
                    cout << "--> Wrong Command!!\n";
                    continue;
                }
            }
        }

        if (iter_turn.current_stage == "your result")
        {
            if (field[field.size()-1][1].value == 0)
            {
                cout << "--> Opponent takes all to hand\n\n";
                for (int i = 0; i < field.size(); i++)
                {
                    opponent_hand.add(field[i][0]);
                    if (field[i][1].value != 0) opponent_hand.add(field[i][1]);
                }
                field.clear();
                opponent_hand.sort();
                iter_turn.next(-3);
            }
            else
            {
                cout << "--> All goes to the dumpster\n\n";
                for (int i = 0; i < field.size(); i++)
                {
                    dumpster.push_back(field[i][0]);
                    dumpster.push_back(field[i][1]);
                }
                field.clear();
                iter_turn.next();
            }
            cout << "check condition\n";
            if (dumpster.size() + opponent_hand.data.size() == 36)
            {
                cout << "--> You've WON!!!!!";
                ONGOING = false;
            }
            if (ONGOING)
            {
                if (dumpster.size() + your_hand.data.size() + opponent_hand.data.size() != 36) while(your_hand.data.size() < 6) if (dumpster.size() + your_hand.data.size() + opponent_hand.data.size() != 36) your_hand.add(game_deck.Pop());
                if (dumpster.size() + your_hand.data.size() + opponent_hand.data.size() != 36) while(opponent_hand.data.size() < 6) if (dumpster.size() + your_hand.data.size() + opponent_hand.data.size() != 36) opponent_hand.add(game_deck.Pop());
                opponent_hand.sort();
                cout << "--> " << trump << " are trumps\n";
                cout << "--> Opponent's hand size: " << opponent_hand.data.size() << "\n\n";
                show(your_hand.data);
            }
        }

        if (iter_turn.current_stage == "opponent go")
        {
            cout << "--> Opponent's move:\n";
            field.push_back({opponent_hand[0], card("0", "0", 0)});
            opponent_hand.discard(0);
            show(field);
            iter_turn.next();
        }

        if (iter_turn.current_stage == "your blocks")
        {
            check = true;
            cout << "--> Your move!\n\n";
            int index;
            string index_;
            while (check)
            {
                cout << "(to block with a card first type 'block')\n";
                cout << "(if you don't want to block type 'take')\n";
                cin >> command;
                if (command == "block"){
                    flag = false;
                    cout << "--> " << trump << " are trumps\n";
                    cout << "--> Opponent's hand size: " << opponent_hand.data.size() << "\n\n";
                    show(your_hand.data);
                    cout << "(type the index of a card you want to block with)\n";
                    cin >> index_;

                    if (IsNumber(index_) && stoi(index_) >= 1 && stoi(index_) <= your_hand.data.size())
                    {
                        index = stoi(index_);
                        index-=1;
                        if (your_hand[index].value > field[field.size()-1][1].value) flag = true;
                        if (flag)
                        {
                            field[field.size()-1][1] = your_hand[index];
                            show(field);
                            your_hand.discard(index);
                            check = false;
                            iter_turn.next();
                        }
                        else
                        {
                            cout << "--> You can't block with this card!!\n";
                            continue;
                        }
                    }
                    else
                    {
                        cout << "--> Wrong Command!!\n";
                        continue;
                    }
                }
                else if (command == "take")
                {
                    check = false;
                    iter_turn.next(2);
                }
                else
                {
                    cout << "--> Wrong Command!!\n";
                    continue;
                }
            }
        }

        if (iter_turn.current_stage == "opponent additions")
        {
            flag = false;
            for (int i = 0; i < opponent_hand.data.size(); i++)
            {
                int tmp_value = opponent_hand[i].value > 14 ? opponent_hand[i].value - 14: opponent_hand[i].value;
                for (int j = 0; j < field.size(); j++)
                {
                    if (tmp_value == field[j][0].value || tmp_value == field[j][0].value - 14) flag = true;
                    if (field[j][1].value != 0 && (tmp_value == field[j][1].value || tmp_value == field[j][1].value - 14)) flag = true;
                    if  (field.size() == your_hand.data.size()) flag = false;
                }
                if (flag)
                {
                    field.push_back({opponent_hand[i], card("0", "0", 0)});
                    opponent_hand.discard(i);
                    show(field);
                    iter_turn.next(-1);
                    break;
                }
            }
            if (!flag) iter_turn.next();
        }

        if (iter_turn.current_stage == "opponent result")
        {
            if (field[field.size()-1][1].value == 0)
            {
                cout << "--> You take all to hand\n\n";
                for (int i = 0; i < field.size(); i++)
                {
                    your_hand.add(field[i][0]);
                    if (field[i][1].value != 0) your_hand.add(field[i][1]);
                }
                show(your_hand.data);
                field.clear();
                iter_turn.next(-3);
            }
            else
            {
                cout << "--> All goes to the dumpster\n\n";
                for (int i = 0; i < field.size(); i++)
                {
                    dumpster.push_back(field[i][0]);
                    dumpster.push_back(field[i][1]);
                }
                field.clear();
                iter_turn.next();
            }
            if (dumpster.size() + your_hand.data.size() == 36)
            {
                cout << "--> You've LOST!!!!!";
                ONGOING = false;
            }
            if (ONGOING)
            {
                if (dumpster.size() + your_hand.data.size() + opponent_hand.data.size() != 36) while(opponent_hand.data.size() < 6) if (dumpster.size() + your_hand.data.size() + opponent_hand.data.size() != 36) opponent_hand.add(game_deck.Pop());
                if (dumpster.size() + your_hand.data.size() + opponent_hand.data.size() != 36) while(your_hand.data.size() < 6) if (dumpster.size() + your_hand.data.size() + opponent_hand.data.size() != 36) your_hand.add(game_deck.Pop());
                opponent_hand.sort();
                cout << "--> " << trump << " are trumps\n";
                cout << "--> Opponent's hand size: " << opponent_hand.data.size() << "\n\n";
                show(your_hand.data);
            }
        }
    }
    return 0;
}
