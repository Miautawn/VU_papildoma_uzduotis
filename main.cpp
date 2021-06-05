#include "main.hpp"

const regex word_exp("[.%,?!/;:\"'()\\]\\[*0-9]");
const regex url_exp("(((http|https)://)?www\\.)?[a-zA-Z0-9_]+\\.[a-zA-Z0-9_]+\\/?[a-zA-Z0-9_]*");

class WordInfo
{
    public:
    int count;
    vector<int> present_in_line;
    
    WordInfo(int line_number) : count{1}, present_in_line{line_number} {}
};


string extract_word(string raw_word) {

    //modified_word
    return regex_replace(raw_word, word_exp, "");
}

bool is_url(string word) {
    if(regex_match(word, url_exp)) return true;
    else return false;
}


void add_word(string word, map<string, WordInfo> &words, int line_number) {

    if(!word.empty()) {
        auto search_result = words.find(word);
        
        //does the key exist?
        if(search_result == words.end()) {
            words.insert({word, WordInfo(line_number)});
        } else {
            if(line_number != search_result->second.present_in_line.back()) {
                search_result->second.present_in_line.push_back(line_number);
            }

            search_result->second.count+=1;
        }
    }
}

void print_word_table(map<string, WordInfo> &words) {

    // word-table
    ofstream output("word_table.txt");
    output<<setw(18)<<left<<"word"<<right<<"count"<<endl;
    output<<string(22, '-')<<endl;
    for(auto word : words) {
        if(word.second.count != 1)
        output<<setw(20)
        <<left<<word.first
        <<right<<word.second.count<<endl;
    } output.close();

}

int calculate_distance(int previous, int current, int diff) {

    int previous_count = to_string(previous).length();
    int current_count = to_string(current).length();

    if(previous_count == current_count) {
        if(diff != 0) return diff + (diff * to_string(current).length()) - 1;
        else return 0;
    } else {

        int sum = 0;
        for(int i = current_count; i>previous_count; i--) {
            int base = pow(10, i - 1);
            sum += calculate_distance(base, current, current - base);
            sum += (current == base) ? i+1 : i+2;
            current = base - 1;
        }
        //first, let's find the closest 10 base number of the higher number
        return sum + calculate_distance(previous, current, (current - previous));
    }

    

}

void print_reference_table(map<string, WordInfo> &words, int line_number) {

    // cross-reference table
    ofstream output("cross_reference_table.txt");
    output<<setw(18)<<left<<"word";
    for(int i = 0; i<line_number; i++) output<<i+1<<" ";
    output<<endl;
    for(auto word : words) {
        if(word.second.count > 1) {
            output<<setw(17)<<left<<word.first;
            for(int i = 0; i<word.second.present_in_line.size(); i++) {
                int previous = (i == 0) ? 0 :  word.second.present_in_line[i-1];
                int diff = word.second.present_in_line[i] - previous;
                int distance = calculate_distance(previous, word.second.present_in_line[i], diff);
                output<<string(distance, ' ')<<'*';
            } output<<endl;
        }
    } output.close();
}

void print_urls(vector<string> &urls) {
    ofstream output("urls.txt");
    for(auto url : urls) output<<url<<endl;
}

int main() {

    map<string, WordInfo> words;
    vector<string> urls;

    //reading the file
    string filename;
    cout<<"Enter the input file: ";
    
    cin>>filename;
    ifstream input(filename);

    if(input) {
        string line;
        string raw_word; //full_word
        
        int line_number = 1;
        while(getline(input, line)) {
            istringstream iss(line);

            //reading the whole line
            while(iss >> raw_word) {
                if(is_url(raw_word)) urls.push_back(raw_word);
                else add_word(extract_word(raw_word), words, line_number);
            } line_number++;

        } 
        input.close();
        line_number--;
        print_word_table(words);
        print_reference_table(words, line_number);
        print_urls(urls);

    } else cout<<"No file found with name: "<<filename<<endl;

}

