typedef union {
  uint32_t raw;
  struct {
    bool jis : 1;
  };
} user_config_t;

extern user_config_t user_config;

void save_persistent(void);