typedef union {
  uint32_t raw;
  struct {
    int16_t to_clickable_movement;
    bool jis : 1;
  };
} user_config_t;

extern user_config_t user_config;

void save_persistent(void);