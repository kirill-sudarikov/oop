import std;

import upload_file;
import count_unique_words;
import find_most_frequent_words;

int main() {
  std::println("--------------------\n"
               "   ЛР №: 5\n"
               " Группа: 6112\n"
               "  Автор: Судариков Кирилл\n"
               "Вариант: 26\n"
               "--------------------"
               "\n");

  std::println("-----------\n"
               "Ввод данных\n"
               "-----------");

  std::print("Введите путь к файлу: ");
  std::string path;
  std::cin >> path;

  try {
    std::vector<std::string> words(upload_file(path));

    std::unordered_set<std::string> stopwords = {
        "i",       "me",       "my",         "myself",     "we",
        "our",     "ours",     "ourselves",  "you",        "your",
        "yours",   "yourself", "yourselves", "he",         "him",
        "his",     "himself",  "she",        "her",        "hers",
        "herself", "it",       "its",        "itself",     "they",
        "them",    "their",    "theirs",     "themselves", "what",
        "which",   "who",      "whom",       "this",       "that",
        "these",   "those",    "am",         "is",         "are",
        "was",     "were",     "be",         "been",       "being",
        "have",    "has",      "had",        "having",     "do",
        "does",    "did",      "doing",      "a",          "an",
        "the",     "and",      "but",        "if",         "or",
        "because", "as",       "until",      "while",      "of",
        "at",      "by",       "for",        "with",       "about",
        "against", "between",  "into",       "through",    "during",
        "before",  "after",    "above",      "below",      "to",
        "from",    "up",       "down",       "in",         "out",
        "on",      "off",      "over",       "under",      "again",
        "further", "then",     "once",       "here",       "there",
        "when",    "where",    "why",        "how",        "all",
        "any",     "both",     "each",       "few",        "more",
        "most",    "other",    "some",       "such",       "no",
        "nor",     "not",      "only",       "own",        "same",
        "so",      "than",     "too",        "very",       "s",
        "t",       "can",      "will",       "just",       "don",
        "should",  "now"};

    std::println("\n"
                 "-----\n"
                 "Ответ\n"
                 "-----");

    std::println("Анализ текста из файла:\n{}\n", path);

    std::println("Общее количество слов в тексте: {}.\n", words.size());

    std::println("Количество уникальных слов: {}.\n",
                 count_unique_words(words, stopwords));

    MostFrequentWords mfw(find_most_frequent_words(words, stopwords));

    std::println("Количество вхождений самого популярного слова: {}.\n",
                 mfw._count);

    std::println("Самые популярные слова:");

    for (const auto& word : mfw._words) {
      std::println("\"{}\"", word);
    }
  } catch (const std::runtime_error& err) {
    std::cerr << "Error: " << err.what() << "\n";
  }

  return 0;
}