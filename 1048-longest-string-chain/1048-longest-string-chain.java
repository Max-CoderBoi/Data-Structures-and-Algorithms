import java.util.*;

class Solution {
    public int longestStrChain(String[] words) {
        Map<String, Integer> map = new HashMap<>();
        Arrays.sort(words, Comparator.comparingInt(String::length));

        for (String word : words) {
            int best = 1; // At least the word itself counts
            for (int i = 0; i < word.length(); i++) {
                String prev = word.substring(0, i) + word.substring(i + 1);
                if (map.containsKey(prev)) {
                    best = Math.max(best, map.get(prev) + 1);
                }
            }
            map.put(word, best);
        }
        return Collections.max(map.values());
    }
}
