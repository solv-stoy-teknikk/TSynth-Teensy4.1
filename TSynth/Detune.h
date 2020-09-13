const static  float  MAXDETUNE = 0.06f; //6%

const static float DETUNE[4][24]  PROGMEM = {
  {0.0f, 0.04f, 0.09f, 0.13f, 0.17f, 0.22f, 0.26f, 0.30f, 0.35f, 0.39f, 0.43f, 0.49f, 0.52f, 0.57f, 0.61f, 0.65f, 0.70f, 0.74f, 0.78f, 0.83f, 0.87f, 0.91f, 0.96f, 1.0f},
  {0.0f, 0.09f, 0.18f, 0.27f, 0.36f, 0.45f, 0.55f, 0.63f, 0.73f, 0.82f, 0.91f, 1.0f, 0.0f, 0.09f, 0.18f, 0.27f, 0.36f, 0.45f, 0.55f, 0.63f, 0.73f, 0.82f, 0.91f, 1.0f},
  {0.0f, 0.14f, 0.29f, 0.43, 0.57f, 0.71f, 0.86f, 1.0f, 0.0f, 0.14f, 0.29f, 0.43, 0.57f, 0.71f, 0.86f, 1.0f, 0.0f, 0.14f, 0.29f, 0.43, 0.57f, 0.71f, 0.86f, 1.0f},
  {0.0f, 0.2f, 0.4f, 0.6f, 0.8f, 1.0f, 0.0f, 0.2f, 0.4f, 0.6f, 0.8f, 1.0f, 0.0f, 0.2f, 0.4f, 0.6f, 0.8f, 1.0f, 0.0f, 0.2f, 0.4f, 0.6f, 0.8f, 1.0f}
};

const static char* CDT_STR[128] = {"Major", "Major", "Major", "Major", "Major", "Major", "Major", "Minor", "Minor", "Minor", "Minor", "Minor", "Minor", "Minor", "Diminished", "Diminished", "Diminished", "Diminished", "Diminished", "Diminished", "Diminished", "Augmented", "Augmented", "Augmented", "Augmented", "Augmented", "Augmented", "Augmented", "Sus 2nd", "Sus 2nd", "Sus 2nd", "Sus 2nd", "Sus 2nd", "Sus 2nd", "Sus 2nd", "Sus 4th", "Sus 4th", "Sus 4th", "Sus 4th", "Sus 4th", "Sus 4th", "Sus 4th", "7th Sus 2nd", "7th Sus 2nd", "7th Sus 2nd", "7th Sus 2nd", "7th Sus 2nd", "7th Sus 2nd", "7th Sus 2nd", "7th Sus 4th", "7th Sus 4th", "7th Sus 4th", "7th Sus 4th", "7th Sus 4th", "7th Sus 4th", "7th Sus 4th", "6th", "6th", "6th", "6th", "6th", "6th", "6th", "7th", "7th", "7th", "7th", "7th", "7th", "7th", "9th", "9th", "9th", "9th", "9th", "9th", "9th", "Major 7th", "Major 7th", "Major 7th", "Major 7th", "Major 7th", "Major 7th", "Major 7th", "Major 9th", "Major 9th", "Major 9th", "Major 9th", "Major 9th", "Major 9th", "Major 9th", "Major 11th", "Major 11th", "Major 11th", "Major 11th", "Major 11th", "Major 11th", "Major 11th", "Minor 6th", "Minor 6th", "Minor 6th", "Minor 6th", "Minor 6th", "Minor 6th", "Minor 6th", "Minor 7th", "Minor 7th", "Minor 7th", "Minor 7th", "Minor 7th", "Minor 7th", "Minor 7th", "Minor 9th", "Minor 9th", "Minor 9th", "Minor 9th", "Minor 9th", "Minor 9th", "Minor 9th", "Minor 11th", "Minor 11th", "Minor 11th", "Minor 11th", "Minor 11th", "Minor 11th", "Minor 11th", "All 12", "All 12"};

const static uint32_t CHORD_DETUNE[12][128]  PROGMEM = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 5, 5, 5, 5, 5, 5, 5, 2, 2, 2, 2, 2, 2, 2, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 1, 1},
  {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 8, 8, 8, 8, 8, 8, 8, 5, 5, 5, 5, 5, 5, 5, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 3, 3, 3, 3, 3, 3, 3, 7, 7, 7, 7, 7, 7, 7, 2, 2},
  {12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 7, 7, 7, 7, 7, 7, 7, 10, 10, 10, 10, 10, 10, 10, 3, 3},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 14, 14, 14, 14, 14, 14, 14, 4, 4},
  {4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 6, 6, 6, 6, 6, 6, 6, 8, 8, 8, 8, 8, 8, 8, 5, 5, 5, 5, 5, 5, 5, 7, 7, 7, 7, 7, 7, 7, 2, 2, 2, 2, 2, 2, 2, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 17, 17, 17, 17, 17, 17, 17, 17, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 17, 17, 17, 17, 17, 17, 17, 5, 5},
  {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 6, 6},
  {12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 5, 5, 5, 5, 5, 5, 5, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 7, 7, 7, 7, 7, 7, 7, 11, 11, 11, 11, 11, 11, 11, 7, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 7, 7},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 6, 6, 8, 8, 8, 8, 8, 8, 8, 5, 5, 5, 5, 5, 5, 5, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 11, 11, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8},
  {4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 14, 14, 14, 14, 14, 14, 14, 4, 4, 4, 4, 4, 4, 4, 14, 14, 14, 14, 14, 14, 11, 11, 11, 11, 11, 11, 11, 11, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 9, 9},
  {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 5, 5, 5, 5, 5, 5, 5, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 14, 14, 14, 14, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 14, 14, 14, 14, 14, 14, 14, 10, 10},
  {12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 6, 6, 6, 6, 6, 6, 6, 8, 8, 8, 8, 8, 8, 8, 5, 5, 5, 5, 5, 5, 5, 7, 7, 7, 7, 7, 7, 7, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 17, 17, 17, 17, 17, 17, 17, 17, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 17, 17, 17, 17, 17, 17, 17, 11, 11}
};

const static float CDT_DETUNE = 0.992f;
