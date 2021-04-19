# Test sequence from waitA0: A0, !A0, A1 => PORTB: 0xF0
tests = [ {'description': 'PINA: 0x01, 0x00, 0x02 => PORTB: 1, state: pressA1',
    'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 2},
        {'inputs': [('PINA', 0x00)], 'iterations': 2},
        {'inputs': [('PINA', 0x02)], 'iterations': 2}],
    'expected': [('PORTB',0xF0)],
    },
    ]
watch = ['state']
