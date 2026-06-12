import std;

export module count_unique_words;

export int count_unique_words(const std::vector<std::string>& words,
	const std::unordered_set<std::string>& stopwords
) {
	std::unordered_set<std::string> unique_words;

	for (const std::string& word : words) {
		if (stopwords.find(word) == stopwords.end()) {
			unique_words.insert(word);
		}
	}

	return unique_words.size();
}