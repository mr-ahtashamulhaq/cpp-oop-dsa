import matplotlib.pyplot as plt
import numpy as np


class PlayfairCipher:
    def __init__(self, keyword: str):
        self.matrix = self._create_key_matrix(keyword)

    def _create_key_matrix(self, keyword: str):
        keyword = keyword.upper().replace('J', 'I')
        matrix = []
        used = set()

        for char in keyword:
            if char.isalpha() and char not in used:
                matrix.append(char)
                used.add(char)

        for char in 'ABCDEFGHIKLMNOPQRSTUVWXYZ':
            if char not in used:
                matrix.append(char)

        return [matrix[i:i + 5] for i in range(0, 25, 5)]

    def prepare_text(self, text: str):
        text = text.upper().replace('J', 'I')
        text = "".join(filter(str.isalpha, text))

        prepared = []
        i = 0

        while i < len(text):
            prepared.append(text[i])

            if i + 1 < len(text):
                if text[i] == text[i + 1]:
                    prepared.append('X')
                    i += 1
                else:
                    prepared.append(text[i + 1])
                    i += 2
            else:
                prepared.append('X')
                i += 1

        return ''.join(prepared)

    def _find_position(self, char):
        for i, row in enumerate(self.matrix):
            for j, letter in enumerate(row):
                if letter == char:
                    return i, j
        return None, None

    def _encrypt_pair(self, a, b):
        r1, c1 = self._find_position(a)
        r2, c2 = self._find_position(b)

        if r1 == r2:
            return self.matrix[r1][(c1 + 1) % 5] + self.matrix[r2][(c2 + 1) % 5]

        if c1 == c2:
            return self.matrix[(r1 + 1) % 5][c1] + self.matrix[(r2 + 1) % 5][c2]

        return self.matrix[r1][c2] + self.matrix[r2][c1]

    def _decrypt_pair(self, a, b):
        r1, c1 = self._find_position(a)
        r2, c2 = self._find_position(b)

        if r1 == r2:
            return self.matrix[r1][(c1 - 1) % 5] + self.matrix[r2][(c2 - 1) % 5]

        if c1 == c2:
            return self.matrix[(r1 - 1) % 5][c1] + self.matrix[(r2 - 1) % 5][c2]

        return self.matrix[r1][c2] + self.matrix[r2][c1]

    def encrypt(self, plaintext: str):
        text = self.prepare_text(plaintext)
        result = ""

        for i in range(0, len(text), 2):
            result += self._encrypt_pair(text[i], text[i + 1])

        return result

    def decrypt(self, ciphertext: str):
        result = ""

        for i in range(0, len(ciphertext), 2):
            result += self._decrypt_pair(ciphertext[i], ciphertext[i + 1])

        return result.replace('X', '')

    def display_matrix(self):
        for row in self.matrix:
            print(row)


class FrequencyAnalyzer:
    @staticmethod
    def count(text: str):
        freq = {}
        for char in text:
            if char.isalpha():
                char = char.upper()
                freq[char] = freq.get(char, 0) + 1
        return freq

    @staticmethod
    def plot(plain_freq, cipher_freq):
        letters = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")

        plain_counts = [plain_freq.get(l, 0) for l in letters]
        cipher_counts = [cipher_freq.get(l, 0) for l in letters]

        x = np.arange(len(letters))
        width = 0.4

        plt.figure()
        plt.bar(x - width / 2, plain_counts, width, label='Plaintext')
        plt.bar(x + width / 2, cipher_counts, width, label='Ciphertext')

        plt.xlabel("Letters")
        plt.ylabel("Frequency")
        plt.title("Frequency Analysis: Plaintext vs Ciphertext")
        plt.xticks(x, letters)
        plt.legend()

        plt.show()


if __name__ == "__main__":
    # Input
    text = (
        "My best friend is a true blessing who brings joy to my life. "
        "We share secrets, laugh often, and support each other through everything. "
        "Their kindness, honesty, and loyalty make them special. "
        "I am incredibly lucky to have such a supportive friend."
    )
    keyword = "SECURITY"

    cipher = PlayfairCipher(keyword)

    print("=" * 60)
    print("PLAYFAIR CIPHER DEMO")
    print("=" * 60)

    print("\n[1] Original Text:\n")
    print(text)

    prepared = cipher.prepare_text(text)
    print("\n[2] Prepared Text (Digraph Ready):\n")
    print(prepared)

    print("\n[3] Key Matrix:\n")
    cipher.display_matrix()

    encrypted = cipher.encrypt(text)
    print("\n[4] Encrypted Text:\n")
    print(encrypted)

    decrypted = cipher.decrypt(encrypted)
    print("\n[5] Decrypted Text:\n")
    print(decrypted)

    print("\n[6] Frequency Analysis:\n")

    plain_freq = FrequencyAnalyzer.count(text)
    cipher_freq = FrequencyAnalyzer.count(encrypted)

    print("Plaintext Frequency:\n", plain_freq)
    print("\nCiphertext Frequency:\n", cipher_freq)

    print("\n[7] Plotting Frequency Comparison...")
    FrequencyAnalyzer.plot(plain_freq, cipher_freq)