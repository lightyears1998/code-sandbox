import logging
import logging.handlers
from os import path
import pathlib


class Logger:
    def __init__(self):
        self.path = path.realpath(path.join(path.dirname(path.realpath(__file__)), '../'))
        self.filename = 'cccat-bot.log'
        self.logger = self.setup_logger()

    def setup_logger(self):
        logger = logging.getLogger()
        logger.setLevel(logging.INFO)
        formatter = logging.Formatter('[%(asctime)s - %(levelname)s]\n%(message)s')
        handler = logging.handlers.RotatingFileHandler(
            f'{self.path}/{self.filename}',
            maxBytes=100 * 1024,
            backupCount=2,
            encoding='utf8'
        )
        handler.setFormatter(formatter)
        logger.addHandler(handler)
        return logger

    def log(self, msg):
        self.logger.info(msg)

    def clean(self):
        logging.shutdown()
        for logfile in pathlib.Path(self.path).glob(self.filename + '*'):
            logfile.unlink()
