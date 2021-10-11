# Test sequence from Begin: A2,A1 => PORTB: 0x00
tests = [ {'description': 'PINA: 0x02, 0x04 => PORTB: 0, SM: unlockDoor',
    'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 2},
        {'inputs': [('PINA', 0x02)], 'iterations': 2},
        {'inputs': [('PINA', 0x04)], 'iterations': 2}],
    'expected': [('PORTB',0x00)],
    },
    ]
watch = ['state']
