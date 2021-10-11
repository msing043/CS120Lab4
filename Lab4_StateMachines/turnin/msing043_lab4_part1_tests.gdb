# Test sequence from stateMachine: A0 => PORTB: 0x02
tests = [ {'description': 'PINA: 0x01=> PORTB: 2, SM: PressWait,
    'steps': [{'inputs': [('PINA', 0x01)], 'iterations': 2},
        {'inputs': [('PINA', 0x00)], 'iterations': 2},
    'expected': [('PORTB',0x02)],
    },
    ]
watch = ['SM']
