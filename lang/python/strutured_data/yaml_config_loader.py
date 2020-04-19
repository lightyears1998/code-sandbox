class ConfigLoader:
    CONFIG_TEMPLATE = """# 代理设置
proxy:
  enable: true
  proxies:
    http: "socks5://127.0.0.1:10808"
    https: "socks5://127.0.0.1:10808"
# 日志设置
logging:
  enable: true
# 邮件通知设置
email:
  enable: true
  server:
      host: "smtp.your.host.com"
      encryption: "SSL"  # 仅支持SSL
      port: 465  # SSL加密的默认端口
      username: "sender@somewhere.com"
      password: "password"
  content: # 邮件正文
      from: "CCCAT Bot" # 发件人名称
      subject: "CCCAT Bot's 报告" # 邮件主题
  sender: 'sender@somewhere.net' # 发件人地址，通常与server的username相同
"""

    def __init__(self):
        self.template = yaml.safe_load(self.CONFIG_TEMPLATE)
        self.configPath = path.realpath(path.join(path.dirname(path.realpath(__file__)), '../config.yml'))

    def get_config(self):
        config = self._load_config_from_file()
        self._check_config_integrity(config)
        return config

    def _load_config_from_file(self):
        try:
            with open(self.configPath, encoding='utf8') as config_file:
                config = yaml.safe_load(config_file.read())
        except FileNotFoundError:
            print(f"无法打开{self.configPath}处的配置文件。")
            print("请先按帮助文档步骤创建配置文件。")
            exit(1)
        return config

    def _check_config_integrity(self, config):
        def check_integrity(to_check, template, prefix=""):
            for entry in template:
                if entry not in to_check:
                    print(f"配置文件中{prefix}{entry}字段缺失，请确认配置文件。")
                    exit(1)
                elif not isinstance(to_check.get(entry), type(template.get(entry))):
                    print(f"配置文件中{prefix}{entry}字段类型应该为{type(template.get(entry))}，请确认配置文件。")
                    exit(1)
                elif isinstance(template.get(entry), dict):
                    check_integrity(to_check.get(entry), template.get(entry), f"{prefix}{entry}.")
        check_integrity(config, self.template)

    def write_default_config(self):
        with open(self.configPath, "w", encoding='utf8') as file:
            file.write(self.CONFIG_TEMPLATE)
