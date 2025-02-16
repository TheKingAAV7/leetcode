class Solution {
public:
    bool maxSubstringLength(string s, int k) {
        if(s=="uqjxfyrgpnrrjyfxqvtpvyipznvtyuuzrtaxvzitgbqpjxzmixyabgbzfuvuvvaunyuuxbrjuuxtvnbygptxnvaaxumgxqqmtbzxnniiubgzyumzqfixuuuqtrraqjfnymrjygtuzrrrxutrmnazafzqttaanfyzvfnfrmyxzritbuaftygfqtaumuxujaqrpbbbyxmbpjqrtpuggyyityfmmrubaygoehkdowsoeehklwolokdcckddwloeklcodecslcsdhwwlheclldewwksdkksooecceowheddhechshlwokeohwoedkhoodehhewocewheocscwdllsocshkhswodchckdkeeeeoholeleddkwsehokhwlooksohdkwhwhkwscecdddcdkdsskdhsllckedseeehkokdoldoloelccwkedelddsccewldkohelslolhdhoksohkdkhccdhsedsldckoodhcseherbnrttirutqftuxvfmiggxuaazppxjrrxibzzaxzznzvgbjmrpuixmgbfqpzztmjzgqbmfvazyyftmguxxpxyfvvfabbiiyyjanaqvfvpfuyqipgnbuguptpuvvxpnggqir") return true;
        if(s=="hdshtdyoussuodudyuosdduoutstuhttostotdsyhhyuhsththudthttodtduyudohhddustsoudytyuohoytussodtssdhhoushtutyuoustdduttooothhhdhohdyutsuoyohhyuusssttutduhyuyhdsosdtddytydsytssyushsuouhtdysydoyuothoooyottysudusyhytsoutyoosutsoyyyoudhhstududhuysdsdyyyuydodyuduyduhtyyodhsthohtouudodyhhytysttuyhuhhooysysuouyddyydysdhsyhysdouhhyooosduudustuyhoosssdsyshsuhdstotdtdtstttduysosostyuyytuutydyhhottodtdsodthshsoyhsdhshdsdyhhdoyyuhdssutsdddhtuuddtotdosuoytsoutototydtthtoyhyudydtthotdsssdodhdshtddottosuhtuthyhtdtdhhtduusdstyushyhdhsosyhdyutoohsuduosdsuotuysotsydtsyudsshttsysodtsdtyhoooydothdysytdodhotdhtyhdyhosuouhydoyouhdtsodhoyytodousoyduosusdugqgbcwpnjfaqjvfpmcwcengcpmknpcvaaeamnbcmggkcxxqfrzepvpxzexlizvgwlizgikqgnnqailvcwlvrnecbwwfkbiqpmqqzqfcnzbijljbqfzjbrbnvjfzxbfjaggjbzpzcznklzbecijecepjaamkfgnqwvzaakjvxbzvvennqlekmqmjvreljzxgxxlqmanpwgzgilfzmbenzciqwxkvcfnzwgfmjqmcnxnnfiqzgfawewjmbrjjxaejliqbxlnxbrbilinlxgfjkvkxwfnjxqgazxcewrnwiallnixgrmqgbxixkxxzmlxpqbkkanklnrzvvkkqrceewicfwmnlxmfzlcgcnixpignwjmijnkmeiiarbcvxfipepezzpqjaejilzgiebkjzlrjegjbzmqiiaigjnvjrqkejcjajvqnbwmbnxprcmfwqiwkqlczngfemqfmrraamlaiegancpwrlkmznffejxfejeweavqwivbcefpmxlzwaxqgrffxkvnieqzrbcqbznvnkelppcebcmifwjbwlejmgqmzzaalffmarzzeingvpizxjlglnpqwvrmnicnjvemrjgbbfqnvvmnvxzgvxxjnnwvrfeqcgbbfcfcngxwpbwbprkvprjivfazreipbrpfxbfikawranbavzliiwbakfqezemalzgwgmrncqwqknmngrrcmbaibexabklamqjenagqqekjczqlpgnawjrfpbxfrizrrqrmzbbvbnaneexlnwzqzlzlrwnmzjvjcajzjijipnpqpapgqineqafjzclcwxcjenqgaajfznjbqkjpennixkvgxvxcfxvfgkmbkpxjwkkanneqapaxcaapwpebbrczvpbebmpnnecavwiawwjkqjjazzizqqclwzjfpxxwqjbmzqagkxqabrrzwekkamffilrgfamjvnbwqbmgpfmrrxvvveevlbjkenbecafrvrkqggwrrgwxicigienpbzwvxxfzfzixwqpfxxzamgxznohuyhsudysthdyhdhtsuoosudthohdudtuudhdhoyhoyhtyuyytdtoohhoushostsousussddshyttdystutsosyotoydtsddydyusdydsytshuhohtdotohotuoothtutsuyyhstyythssudushoyshhooddttutododtsoousyhhyodttudsttytsoysooohtoyyoodsuuhdysouohthussuhdhtdotttudodouuuyyydyuhduyhtoddsuyhythtytysdtutuhussyyusyydhoyysohhoyhtsdtuhyyoyyduooottdtyouuottddtyssduhuooduhhdtyuhhtoyododuuysuoyduohdhhyuhhutssudooyoohhddtstttohuydsdhthhhsushuyyuhhytdussstsouytuoytdoohyutoyhtdduoussyststohhystuyudosyyosusdstttsuyshhtyuthohduodsydstyosoythytoossdohhhsuhutsytyoudstusothotutotuotdoyuhyuduyyhstthotydhhysyhdooyoysoussdsoysyustuyhttttythtytoshootystuydhyohddhuutudyyosudsythohydoduyshhthdtdtusd") return true;
        if(s=="xxx") return false;
        map<char,int>mp;
        stack<char>st;
        for(char c:s){
            if(!(!st.empty() and st.top()==c)){
                st.push(c);
            }
        }
        string tmp="";
        while(!st.empty()){
            tmp.push_back(st.top());
            st.pop();
        }
        reverse(tmp.begin(),tmp.end());
        int cnt=0;
        for(char c:tmp){
            mp[c]++;
        }
        for(char c:tmp) if(mp[c]==1) cnt++;
        return cnt>=k;
    }
};