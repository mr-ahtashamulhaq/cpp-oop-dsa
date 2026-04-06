# 🔐 Playfair Cipher with Frequency Analysis

A clean implementation of the **Playfair Cipher** in Python, including encryption, decryption, and frequency analysis with visualization.

---

## 📌 Overview

This project demonstrates:

* Playfair cipher encryption and decryption
* Key matrix generation using a keyword
* Plaintext preprocessing (digraph formation)
* Frequency analysis of plaintext vs ciphertext
* Visualization using bar charts

The goal is to understand how classical ciphers behave and how frequency patterns change after encryption.

---

## ⚙️ How It Works

### 1. Key Matrix Generation

* A 5×5 matrix is created using a keyword
* Duplicate letters are removed
* Letter **J is merged with I**

---

### 2. Plaintext Preparation

* Converts text to uppercase
* Removes non-alphabet characters
* Splits text into digraphs
* Inserts `X` between repeated letters
* Pads with `X` if needed

---

### 3. Encryption Rules

Each pair of letters is encrypted using:

* **Same row** → shift right
* **Same column** → shift down
* **Rectangle rule** → swap columns

---

### 4. Decryption

Reverse of encryption:

* **Same row** → shift left
* **Same column** → shift up
* **Rectangle rule** → swap columns

---

### 5. Frequency Analysis

* Counts frequency of each letter (A–Z)
* Compares plaintext vs ciphertext
* Displays results using a bar chart

---

## 📊 Example Output

* Plaintext and ciphertext frequencies are printed
* A visual comparison chart is displayed
* Helps observe how Playfair reduces obvious frequency patterns

---

## 🧠 Why This Matters

* Shows why simple ciphers fail against frequency analysis
* Demonstrates how Playfair improves security using digraphs
* Builds intuition for classical cryptography

---

## 🚀 Getting Started

### 1. Move into directory

```bash
cd playfair-cipher
```

### 2. Install dependencies

```bash
pip install matplotlib numpy
```

### 3. Run the program

```bash
python main.py
```

---

## 📁 Project Structure

```
playfair-cipher/
│
├── playfair-cipher.py                # Main execution script
├── README.md             # Project documentation
```

---

## 🛠 Features

* Clean class-based design
* Modular and easy to extend
* Visualization support
* Suitable for academic use and demonstrations

---

## 📌 Future Improvements

* Add command-line interface (CLI)
* Export plots as images
* Add unit tests
* Support custom filler characters

---

## 👨‍💻 Author

Developed as part of an Information Security assignment.

---

## 📜 License

This project is open-source and available under the MIT License.
