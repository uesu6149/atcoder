class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children; // �q�m�[�h���i�[����n�b�V���}�b�v
    bool isEndOfWord; // ������̏I�[�������t���O

    TrieNode() : isEndOfWord(false) {} // �R���X�g���N�^�ŏI�[�t���O��������
};

class Trie {
public:
    TrieNode* root; // ���m�[�h

    Trie() : root(new TrieNode()) {} // �R���X�g���N�^�ō��m�[�h�𐶐�

    // ������̑}��
    void insert(std::string word) {
        TrieNode* current = root; // ���݂̃m�[�h�����m�[�h�ɐݒ�
        for (char c : word) { // ������̊e�����ɂ��ă��[�v
            // ���݂̃m�[�h�̎q�m�[�h�ɁA���݂̕����ɑΉ�����m�[�h�����݂��邩�m�F
            if (current->children.find(c) == current->children.end()) {
                // ���݂��Ȃ��ꍇ�A�V�����m�[�h���쐬
                current->children[c] = new TrieNode();
            }
            // ���݂̃m�[�h���A���̕����ɑΉ�����q�m�[�h�Ɉړ�
            current = current->children[c];
        }
        // ������̏I�[�ɒB������A�I�[�t���O��ݒ�
        current->isEndOfWord = true;
    }

    // ������̌���
    bool search(std::string word) {
        TrieNode* current = root; // ���݂̃m�[�h�����m�[�h�ɐݒ�
        for (char c : word) { // ������̊e�����ɂ��ă��[�v
            // ���݂̃m�[�h�̎q�m�[�h�ɁA���݂̕����ɑΉ�����m�[�h�����݂��邩�m�F
            if (current->children.find(c) == current->children.end()) {
                // ���݂��Ȃ��ꍇ�A������̓g���C�؂ɑ��݂��Ȃ�
                return false;
            }
            // ���݂̃m�[�h���A���̕����ɑΉ�����q�m�[�h�Ɉړ�
            current = current->children[c];
        }
        // ������̏I�[�܂œ��B������A�I�[�t���O���m�F
        return current->isEndOfWord;
    }

    // �v���t�B�b�N�X����
    bool startsWith(std::string prefix) {
        TrieNode* current = root; // ���݂̃m�[�h�����m�[�h�ɐݒ�
        for (char c : prefix) { // �v���t�B�b�N�X�̊e�����ɂ��ă��[�v
            // ���݂̃m�[�h�̎q�m�[�h�ɁA���݂̕����ɑΉ�����m�[�h�����݂��邩�m�F
            if (current->children.find(c) == current->children.end()) {
                // ���݂��Ȃ��ꍇ�A�v���t�B�b�N�X�̓g���C�؂ɑ��݂��Ȃ�
                return false;
            }
            // ���݂̃m�[�h���A���̕����ɑΉ�����q�m�[�h�Ɉړ�
            current = current->children[c];
        }
        // �v���t�B�b�N�X�̏I�[�܂œ��B������A�v���t�B�b�N�X�̓g���C�؂ɑ��݂���
        return true;
    }
};