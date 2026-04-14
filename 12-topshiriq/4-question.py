class Subscriber:
    def __init__(self, name):
        self.name = name

    def update(self, video_title):
        print(f"Уведомление для {self.name}: На канале вышло новое видео — '{video_title}'!")


class YouTubeChannel:
    def __init__(self, channel_name):
        self.channel_name = channel_name
        self._subscribers = []  # Список тех, кто нажал на колокольчик

    def subscribe(self, user):
        print(f"--- {user.name} подписался на {self.channel_name} ---")
        self._subscribers.append(user)

    def unsubscribe(self, user):
        print(f"--- {user.name} отписался от {self.channel_name} ---")
        self._subscribers.remove(user)

    def upload_video(self, title):
        print(f"\n🎬 Канал {self.channel_name} загружает видео: {title}")
        self._notify_subscribers(title)

    def _notify_subscribers(self, video_title):
        for sub in self._subscribers:
            sub.update(video_title)


# Создаем канал
my_tech_channel = YouTubeChannel("IT-Профи")

# Создаем зрителей
user1 = Subscriber("Алексей")
user2 = Subscriber("Марина")
user3 = Subscriber("Богдан")

# Подписываем их (они жмут на колокольчик)
my_tech_channel.subscribe(user1)
my_tech_channel.subscribe(user2)
my_tech_channel.subscribe(user3)

# Канал выпускает ролик — уведомления летят всем троим
my_tech_channel.upload_video("Как выучить Python за 5 минут")

# Один зритель устал от уведомлений и отписался
my_tech_channel.unsubscribe(user2)

# Выходит новое видео — уведомление получат только двое
my_tech_channel.upload_video("Что такое паттерны проектирования")
