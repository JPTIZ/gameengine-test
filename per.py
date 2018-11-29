'''Main game module.'''
import persona_x
from persona_x import Sprite

# TODO: Consertar resize.


SYSTEM = {
    'titlebg': 'res/system/title-stub.jpg',
}

GRAPHICS = {
    'res': (800, 600),
}


def center(sprite, ox=0, oy=0):
    bounds = sprite.local_bounds
    gw, gh = GRAPHICS['res']
    sprite.position = (
        ox + (gw - bounds.width) / 2,
        oy + (gh - bounds.height) / 2,
    )


class SceneTitle():
    OPTIONS = [
        'res/system/newgame.png',
        'res/system/loadgame.png',
    ]

    def __init__(self, game):
        self.game = game
        self.option = 0

    def start(self):
        print('starting it all')

        self.background = Sprite(self.game, SYSTEM['titlebg'])

        center(self.background, 0, -40)

        self.game.add_sprite(self.background)

        self.options = []
        for i, filename in enumerate(SceneTitle.OPTIONS):
            sprite = Sprite(self.game, filename)
            self.options.append(sprite)

            size = sprite.texture.size
            w, h = size.x, size.y
            print(f'{w}, {h}')
            sprite.src_rect = persona_x.IntRect(0, 0, w // 2, h)

            center(sprite, 0, 120 + i*20)

            self.game.add_sprite(sprite)

        self.highlight_options()

        print('Done start!')

    def highlight_options(self):
        for i, sprite in enumerate(self.options):
            size = sprite.texture.size
            w, h = size.x, size.y

            half = w // 2

            sprite.src_rect = persona_x.IntRect(
                half * (1 if i == self.option else 0),
                0,
                half,
                int(h),
            )

    def update(self):
        self.highlight_options()

    def terminate(self):
        self.game.clear_sprites()
        print('Terminated.')


def x(game):
    print(game)
    scene = SceneTitle(game)

    scene.start()
    while game.running():
        game.update()
        scene.update()
        game.display()
    scene.terminate()


if __name__ == '__main__':
    print('Hello, ')

    game = persona_x.Game(x)
    game.start()

    print('World')
