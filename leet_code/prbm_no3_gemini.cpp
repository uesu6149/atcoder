class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;
        int maxLength = 0, start = 0;

        for (int end = 0; end < s.length(); ++end) {
            if (charIndexMap.find(s[end]) != charIndexMap.end()) {
                start = max(start, charIndexMap[s[end]] + 1);
            }
            charIndexMap[s[end]] = end;
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // �n�b�V���}�b�v charIndexMap ���g���āA�e�����Ƃ��̍Ō�̏o���ʒu�i�C���f�b�N�X�j���L�^���܂��B
        unordered_map<char, int> charIndexMap;
        // maxLength �́A����܂łɌ��������Œ��̕���������̒������i�[���܂��B
        int maxLength = 0;
        // start �́A���݂̕���������̊J�n�ʒu�i�C���f�b�N�X�j���i�[���܂��B
        int start = 0;

        // ������ s �� end �C���f�b�N�X�ő������܂��B
        for (int end = 0; end < s.length(); ++end) {
            // ���݂̕��� s[end] �� charIndexMap �ɑ��݂��邩�ǂ������m�F���܂��B
            if (charIndexMap.find(s[end]) != charIndexMap.end()) {
                // ���� s[end] �����ɑ��݂���ꍇ�A
                // start ���A�ȑO�� s[end] �̈ʒu�̎��̕����܂Ői�߂܂��B
                // ����́A�d�����镶��������������Ɋ܂܂�Ȃ��悤�ɂ��邽�߂ł��B
                // max(start, charIndexMap[s[end]] + 1) �́A
                // start ���ȑO�� s[end] �̈ʒu�����O�ɂ������ꍇ�ɁA
                // start ���X�V����Ȃ��悤�ɂ��܂��B
                start = max(start, charIndexMap[s[end]] + 1);
            }
            // ���݂̕��� s[end] �̈ʒu�� charIndexMap �ɋL�^���܂��B
            // ���� s[end] �����ɑ��݂���ꍇ�́A���̈ʒu���X�V����܂��B
            charIndexMap[s[end]] = end;
            // ���݂̕���������̒������v�Z���AmaxLength ���X�V���܂��B
            maxLength = max(maxLength, end - start + 1);
        }

        // �Œ��̕���������̒�����Ԃ��܂��B
        return maxLength;
    }
};