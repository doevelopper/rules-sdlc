import logging
import yaml
import os

from datetime import datetime

class fileTransfer:

    def __init__(self):

        logging.basicConfig(filename="event.log",
                        filemode='a',
                        format='%(asctime)s,%(msecs)d %(name)s %(levelname)s %(message)s',
                        datefmt='%H:%M:%S',level = logging.DEBUG)
        self.logger = logging.getLogger()
        self.config = self.init_config()
        self.logger.info(self.config)

    def init_config(self):
      self.logger.info('Reading Configuration file')

    def connect(self):

        try:
            self.logger.info('Connecting to ...')
        except:
            self.logger.error("Unable to connect to ...", exc_info=True)
