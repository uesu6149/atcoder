class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children; // 子ノードを格納するハッシュマップ
    bool isEndOfWord; // 文字列の終端を示すフラグ

    TrieNode() : isEndOfWord(false) {} // コンストラクタで終端フラグを初期化
};

class Trie {
public:
    TrieNode* root; // 根ノード

    Trie() : root(new TrieNode()) {} // コンストラクタで根ノードを生成

    // 文字列の挿入
    void insert(std::string word) {
        TrieNode* current = root; // 現在のノードを根ノードに設定
        for (char c : word) { // 文字列の各文字についてループ
            // 現在のノードの子ノードに、現在の文字に対応するノードが存在するか確認
            if (current->children.find(c) == current->children.end()) {
                // 存在しない場合、新しいノードを作成
                current->children[c] = new TrieNode();
            }
            // 現在のノードを、次の文字に対応する子ノードに移動
            current = current->children[c];
        }
        // 文字列の終端に達したら、終端フラグを設定
        current->isEndOfWord = true;
    }

    // 文字列の検索
    bool search(std::string word) {
        TrieNode* current = root; // 現在のノードを根ノードに設定
        for (char c : word) { // 文字列の各文字についてループ
            // 現在のノードの子ノードに、現在の文字に対応するノードが存在するか確認
            if (current->children.find(c) == current->children.end()) {
                // 存在しない場合、文字列はトライ木に存在しない
                return false;
            }
            // 現在のノードを、次の文字に対応する子ノードに移動
            current = current->children[c];
        }
        // 文字列の終端まで到達したら、終端フラグを確認
        return current->isEndOfWord;
    }

    // プレフィックス検索
    bool startsWith(std::string prefix) {
        TrieNode* current = root; // 現在のノードを根ノードに設定
        for (char c : prefix) { // プレフィックスの各文字についてループ
            // 現在のノードの子ノードに、現在の文字に対応するノードが存在するか確認
            if (current->children.find(c) == current->children.end()) {
                // 存在しない場合、プレフィックスはトライ木に存在しない
                return false;
            }
            // 現在のノードを、次の文字に対応する子ノードに移動
            current = current->children[c];
        }
        // プレフィックスの終端まで到達したら、プレフィックスはトライ木に存在する
        return true;
    }
};