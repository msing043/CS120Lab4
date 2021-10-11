# Test sequence from Initializer: A0 => PORTB: 0x08
tests = [ {'description': 'PINA: 0x01 => PORTB: 0x08, SM: ,
    'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 2},
        {'inputs': [('PINA', 0x00)], 'iterations': 2},
        {'inputs': [('PINA', 0x02)], 'iterations': 2}],
    'expected': [('PORTB',0x08)],
    },
    ]
watch = ['SM']
